#include "../inc/Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	try {
		Bureaucrat	a("a", 150);
		Bureaucrat	b("b", 1);

		PresidentialPardonForm	form1("target");
		RobotomyRequestForm			form2("target");
		ShrubberyCreationForm		form3("target");
		form1.execute(b);
		form2.execute(a);
		form3.execute(b);

		a.executeForm(form1);
		b.executeForm(form1);
	}
	catch (const std::exception &e) {
		std::cout << "error : " << e.what() << std::endl;
	}
}
