#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : \
	AForm("Presidential Pardon", _target, 145, 137) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src) {}

PresidentialPardonForm	&PresidentialPardonForm::operator = (const PresidentialPardonForm& rhs) {
	this->AForm::operator=(rhs);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	try {
		this->checkExecutor(executor);
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "[PresidentialPardonForm] error : " << e.what() << '\n';
	}
}

AForm *PresidentialPardonForm::create(std::string const& target) {
	return new PresidentialPardonForm(target);
}
