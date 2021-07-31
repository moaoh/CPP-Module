#include "Karen.hpp"

int main(void)
{
	Karen	karen;

	karen.complain("DEBUG");
	std::cout << "\n";
	karen.complain("INFO");
	std::cout << "\n";
	karen.complain("WARNING");
	std::cout << "\n";
	karen.complain("ERROR");
	std::cout << "\n";

	return (0);
}