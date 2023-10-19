#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const& src) {  (void)src; }

Intern &Intern::operator = (Intern const& rhs) {
	(void)rhs;
	return *this;
}

Intern::~Intern() {}

const char* Intern::InvalidFormName::what() const throw() {
	return ("Intern can't create Form");
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	const std::string formNames[3] = {
		"Shrubbery Creation",
		"robotomy request",
		"Presidential Pardon"};

	AForm *(*forms[3])(std::string const &target) = {
		&ShrubberyCreationForm::create,
		&RobotomyRequestForm::create,
		&PresidentialPardonForm::create
	};

	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i](target);
		}
	}
	throw Intern::InvalidFormName();
}


