#include "../inc/PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string _target) :
	AForm("none", _target, 145, 137) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	try {
		this->checkExecutor(executor);
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "[PresidentialPardonForm] error :" << e.what() << '\n';
	}
}
