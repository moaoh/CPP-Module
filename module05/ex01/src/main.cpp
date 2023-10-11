#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	try {
		Bureaucrat	a("a", 150);
		Bureaucrat	b("b", 1);
		Form				subject("subject", 50, 50);

		std::cout << subject;
		b.signForm(subject);
		std::cout << subject;
		a.signForm(subject);
		b.signForm(subject);
	}
	catch (const std::exception &e) {
		std::cout << "error : " << e.what() << std::endl;
	}
}
