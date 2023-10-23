#ifndef SCALARCONVERTER_HPP_
#define SCALARCONVERTER_HPP_

#include <iostream>
#include <limits>

class ScalarConverter
{
public:

	static void 	convert(const std::string &value);

	class NonDisplayableException : public std::exception {
	public:
		const char *what() const throw();
	};
	class ImpossibleException : public std::exception {
	public:
		const char *what() const throw();
	};
	class OverflowsException : public std::exception {
	public:
		const char *what() const throw();
	};

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter &operator=(const ScalarConverter& rhs);
	~ScalarConverter();

	static void		toCharValue(const std::string &strValue);
	static void		toIntValue(const std::string &strValue);
	static void		toFloatValue(const std::string &strValue);
	static void		toDoubleValue(const std::string &strValue);
};

#endif
