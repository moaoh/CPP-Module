#include "ScalarConverter.hpp"

int		main(int ac, char *av[])
{
	try {
		if (ac != 2) {
			throw std::invalid_argument("Invalid argument");
		}
		ScalarConverter::convert(av[1]);
	}
	catch(const std::exception& e) {
		std::cerr << "error: " << e.what() << '\n';
	}
	return 0;
}

/*
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

./convert a
char: a
int: 97
float: 97.0f
double: 97.0
*/


