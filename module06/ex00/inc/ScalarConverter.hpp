#ifndef SCALARCONVERTER_HPP_
#define SCALARCONVERTER_HPP_

#include <iostream>

class ScalarConverter
{
public:
	static void		printCharValue(const double &doubleValue);
	static void		printIntValue(const double &doubleValue);
	static void		printFloatValue(const double &doubleValue);
	static void		printDoubleValue(const double &doubleValue);

	static void 	convert(const std::string &value);

	class NonDisplayable : public std::exception {
	public:
		const char *what() const throw();
	};
	class Impossible : public std::exception {
	public:
		const char *what() const throw();
	};

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter &operator=(const ScalarConverter& rhs);
	~ScalarConverter();
};

#endif
