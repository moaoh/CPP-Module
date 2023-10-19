#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main() {
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf = someRandomIntern.makeForm("error form", "Bender");
	}
	catch (const std::exception &e) {
		std::cout << "error : " << e.what() << std::endl;
	}
}
