#include "Bureaucrat.hpp"

int	main() {
	try {
		Bureaucrat	a("a", 150);
		Bureaucrat	b("b", 1);

		a.upGrade();
		b.downGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		b.setGrade(0);

		a.downGrade();
		a.downGrade();
	}
	catch (std::exception &e) {
		std::cout << "error : " << e.what() << std::endl;
	}
}
