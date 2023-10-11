#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	try {
		Bureaucrat	a("a", 150);
		Bureaucrat	b("b", 1);
		Form				text("subject", 50, 50);

		b.signForm(text);
	}
	catch (std::exception &e) {
		std::cout << "error : " << e.what() << std::endl;
	}
}
