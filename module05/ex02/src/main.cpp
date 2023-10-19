#include "../inc/Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	try {
		Bureaucrat	a("a", 150);
		Bureaucrat	b("b", 1);

		PresidentialPardonForm	form1("target1");
		RobotomyRequestForm			form2("target2");
		ShrubberyCreationForm		form3("target3");

		a.signForm(form3);
		a.executeForm(form3);

		b.signForm(form3);
		b.executeForm(form3);
	}
	catch (const std::exception &e) {
		std::cout << "error : " << e.what() << std::endl;
	}
}
