#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int	main() {
	Bureaucrat	superBureaucrat("superBureaucrat", 1);
	Bureaucrat	weakBureaucrat("weakBureaucrat", 150);
	Form				subject("subject", 50, 50);

	std::cout << subject;
	superBureaucrat.signForm(subject);
	std::cout << subject;
	weakBureaucrat.signForm(subject);
	superBureaucrat.signForm(subject);
}
