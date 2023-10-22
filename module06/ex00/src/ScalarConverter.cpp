#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter& rhs) {
	(void)rhs;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

const char* ScalarConverter::NonDisplayableException::what() const throw() {
	return ("Non displayable");
}

const char* ScalarConverter::ImpossibleException::what() const throw() {
	return ("impossible");
}

const char* ScalarConverter::OverflowsException::what() const throw() {
	return ("overflow");
}

void	ScalarConverter::toCharValue(const std::string &strValue) {
	char	charValue;
	int		intValue;
	try {
		if (strValue.size() == 1 && (strValue[0] < '0' || '9' < strValue[0])) {
			charValue = static_cast<int>(strValue[0]);
			if (charValue < 0 || 127 < charValue) {
				throw ImpossibleException();
			}
		}
		else {
			intValue = std::stoi(strValue);
			if (intValue < 0 || 255 < intValue) {
				throw ImpossibleException();
			}
			charValue = std::stoi(strValue);
		}
	}
	catch(...) {
		throw ImpossibleException();
	}
	if (!std::isprint(charValue)) {
		throw NonDisplayableException();
	}
	std::cout << '\'' << charValue << '\'' << std::endl;
}

void	ScalarConverter::toIntValue(const std::string &strValue) {
	int intValue;
	try {
		if (strValue.size() == 1) {
			intValue = static_cast<int>(strValue[0]);
		}
		else {
			intValue = std::stoi(strValue);
		}
	}
	catch (const std::out_of_range& e) {
		throw OverflowsException();
	}
	catch(...) {
		throw ImpossibleException();
	}
	std::cout << intValue << std::endl;
}

void	ScalarConverter::toFloatValue(const std::string &strValue) {
	float floatValue;
	try {
		if (strValue.size() == 1) {
			floatValue = static_cast<float>(strValue[0]);
		}
		else {
			floatValue = std::stof(strValue);
		}
	}
	catch(...) {
		throw ImpossibleException();
	}
	if (!std::isprint(floatValue)) {
		throw OverflowsException();
	}
	if (!std::isnan(floatValue)) {
		std::cout << ".0";
	}
	std::cout << "f" << std::endl;
}

void	ScalarConverter::toDoubleValue(const std::string &strValue) {
	double doubleValue;
	try {
		if (strValue.size() == 1) {
			doubleValue = static_cast<double>(strValue[0]);
		}
		else {
			/* 2.14748e+09형태의 값을 -> 2147483650 형식으로 변환 필요. */
			doubleValue = std::stod(strValue);
		}
	}
	catch(...) {
		throw ImpossibleException();
	}
	std::cout << doubleValue;
	if (!std::isnan(doubleValue)) {
		std::cout << ".0";
	}
}

void ScalarConverter::convert(const std::string &value) {
	try {
		std::cout << "char: ";
		toCharValue(value);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "int: ";
		toIntValue(value);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "float: ";
		toFloatValue(value);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "double: ";
		toDoubleValue(value);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
