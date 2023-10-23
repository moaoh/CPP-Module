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
	char	*endptr;
	try {
		double	doubleValue = std::strtod(strValue.c_str(), &endptr);
		if (doubleValue < 0 || 127 < doubleValue) {
			throw ImpossibleException();
		}
		if (*endptr == '\0' || *endptr == 'f') {
			if (std::isnan(doubleValue) || std::isinf(doubleValue)) {
				throw ImpossibleException();
			}
			charValue = static_cast<char>(doubleValue);
		}
		else {
			if (strValue.size() != 1) {
				throw ImpossibleException();
			}
			charValue = strValue[0];
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
	int		intValue;
	char	*endptr;
	double	doubleValue;
	try {
		doubleValue = std::strtod(strValue.c_str(), &endptr);
		if (*endptr == '\0' || *endptr == 'f') {
			if (std::isnan(doubleValue) || std::isinf(doubleValue)) {
				throw ImpossibleException();
			}
			intValue = static_cast<int>(doubleValue);
		}
		else {
			if (strValue.size() != 1) {
				throw ImpossibleException();
			}
			intValue = *endptr;
		}
	}
	catch(...) {
		throw ImpossibleException();
	}
	if (doubleValue < INT_MIN || INT_MAX < doubleValue) {
		throw OverflowsException();
	}
	std::cout << intValue << std::endl;
}

void	ScalarConverter::toFloatValue(const std::string &strValue) {
	float floatValue;
	char	*endptr;
	double	doubleValue;
	try {
		doubleValue = std::strtod(strValue.c_str(), &endptr);
		if (*endptr == '\0' || *endptr == 'f') {
			floatValue = static_cast<float>(doubleValue);
		}
		else {
			if (strValue.size() != 1) {
				throw ImpossibleException();
			}
			floatValue = *endptr;
		}
	}
	catch(...) {
		throw ImpossibleException();
	}
	if (doubleValue < INT_MIN || INT_MAX < doubleValue) {
		throw OverflowsException();
	}
	std::cout << floatValue;
	if (!std::isnan(floatValue) && !std::isinf(floatValue)) {
		std::cout << ".0";
	}
	std::cout << 'f' << std::endl;
}

void	ScalarConverter::toDoubleValue(const std::string &strValue) {
	double	doubleValue_;
	char	*endptr;
	try {
		double	doubleValue = std::strtod(strValue.c_str(), &endptr);
		if (*endptr == '\0' || *endptr == 'f') {
			doubleValue_ = static_cast<double>(doubleValue);
		}
		else {
			if (strValue.size() != 1) {
				throw ImpossibleException();
			}
			doubleValue_ = *endptr;
		}
	}
	catch(...) {
		throw ImpossibleException();
	}
	std::cout << doubleValue_;
	if (!std::isnan(doubleValue_) && !std::isinf(doubleValue_)) {
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
