#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter& rhs) {
	(void)rhs;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

const char* ScalarConverter::NonDisplayable::what() const throw() {
	return ("Non displayable");
}

const char* ScalarConverter::Impossible::what() const throw() {
	return ("impossible");
}

void	ScalarConverter::printCharValue(const double &doubleValue) {
	char charValue_ = static_cast<char>(doubleValue);
	if (!charValue_) throw ScalarConverter::NonDisplayable();
	std::cout << "char: " << charValue_ << std::endl;
}

void	ScalarConverter::printIntValue(const double &doubleValue) {
	int intValue_ = static_cast<int>(doubleValue);
	std::cout << "int: " << intValue_ << std::endl;
}

void	ScalarConverter::printFloatValue(const double &doubleValue) {
	float floatValue_ = static_cast<float>(doubleValue);
	std::cout << "float: " << floatValue_ << std::endl;
}

void	ScalarConverter::printDoubleValue(const double &doubleValue) {
	std::cout << "double: " << doubleValue << std::endl;
}

void ScalarConverter::convert(const std::string &value) {
	double doubleValue_ = std::stod(value);
	try {
		printCharValue(doubleValue_);
	}
	catch(const std::exception& e) {
		std::cerr << "char: " << e.what() << '\n';
	}
	try {
		printIntValue(doubleValue_);
	}
	catch(const std::exception& e) {
		std::cerr << "int: " << e.what() << '\n';
	}
	try {
		printFloatValue(doubleValue_);
	}
	catch(const std::exception& e) {
		std::cerr << "float: " << e.what() << '\n';
	}
	try {
		printDoubleValue(doubleValue_);
	}
	catch(const std::exception& e) {
		std::cerr << "double: " << e.what() << '\n';
	}
}
