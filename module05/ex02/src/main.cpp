#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	try {
		Bureaucrat	superBureaucrat("superBureaucrat", 1);
		Bureaucrat	weakBureaucrat("weakBureaucrat", 150);

		PresidentialPardonForm	form1("target1");
		RobotomyRequestForm			form2("target2");
		ShrubberyCreationForm		form3("target3");

		// error case ===
		weakBureaucrat.signForm(form3);
		weakBureaucrat.executeForm(form3);

		superBureaucrat.executeForm(form1);
		/// =============

		superBureaucrat.signForm(form1);
		superBureaucrat.executeForm(form1);

		superBureaucrat.signForm(form2);
		superBureaucrat.executeForm(form2);

		superBureaucrat.signForm(form3);
		superBureaucrat.executeForm(form3);
	}
	catch (const std::exception &e) {
		std::cout << "error : " << e.what() << std::endl;
	}
}
