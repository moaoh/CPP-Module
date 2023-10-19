#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main() {
	try {
		Intern intern_;
		AForm* testForm;
		AForm* erorrForm;
		Bureaucrat	superBureaucrat("superBureaucrat", 1);

		testForm = intern_.makeForm("robotomy request", "Bender");
		superBureaucrat.signForm(*testForm);
		superBureaucrat.executeForm(*testForm);
		delete testForm;

		// error case ======
		erorrForm = intern_.makeForm("error form", "Bender");
		superBureaucrat.signForm(*erorrForm);
		superBureaucrat.executeForm(*erorrForm);
		delete erorrForm;
	}
	catch (const std::exception &e) {
		std::cout << "error : " << e.what() << std::endl;
	}
}
