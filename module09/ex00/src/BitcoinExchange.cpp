#include <fstream>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <cstring>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	this->_bitcoinData = src._bitcoinData;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	if (this == &rhs) return *this;
	this->_bitcoinData = rhs._bitcoinData;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static int countOccurrences(const std::string& str, char target) {
	int count = 0;
	for (std::size_t i = 0; i < str.length(); i++) {
		if (str[i] == target) {
			count++;
		}
	}
	return count;
}

/*
static bool hasExtension(const char* fileName, const char* extension) {
	const char* dotPosition = std::strrchr(fileName, '.');
	if (dotPosition == nullptr || dotPosition == fileName || *(dotPosition + 1) == '\0') {
		return false;
	}
	const char* fileExtension = dotPosition + 1;
	return std::strcmp(fileExtension, extension) == 0;
}
*/

static int checkValidFirstLine(std::string line, std::string str) {
	size_t pos = line.find(str);
	if (pos == std::string::npos) {
		return 1;
	}
	return 0;
}

void	BitcoinExchange::inBitcoinData() {
	std::ifstream outFile("data.csv");
	if (!outFile.is_open()) {
		throw std::runtime_error("not open file. : data.csv");
	}
	std::string line;
	std::getline(outFile, line);
	if (checkValidFirstLine(line, "date,exchange_rate")) {
		return throw std::runtime_error("invalid format file : date,exchange_rate");
	}
	while(std::getline(outFile, line)) {
		std::size_t pos = line.find(",");
		if (pos == std::string::npos || countOccurrences(line, ',') != 1) {
			throw std::runtime_error("invalid csv file.");
		}
		char* endPtr;
		std::string key = line.substr(0, pos);
		double value = strtod(line.substr(pos + 1).c_str(), &endPtr);
		this->_bitcoinData.insert(std::make_pair(key, value));
	}
}

static bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool isValidDate(std::string line, std::string key) {
	if (countOccurrences(key, '-') != 2) {
		throw std::runtime_error("bad input => " + line);
	}
	int firstTarget = key.find("-");
	int secondTarget = key.rfind("-");
	int year = std::atoi(key.substr(0, firstTarget).c_str());
	int month = std::atoi(key.substr(firstTarget + 1, secondTarget).c_str());
	int day = std::atoi(key.substr(secondTarget + 1).c_str());
	const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year < 1000 || 10000 <= year || month < 1 || 12 < month || day < 1) {
		throw std::runtime_error("bad input => " + line);
	}
	if (month == 2 && isLeapYear(year)) {
		if (day < 1 || 29 < day) {
			throw std::runtime_error("bad input => " + line);
		}
		return true;
	}
	else {
		if (day < 1 || daysInMonth[month] < day) {
			throw std::runtime_error("bad input => " + line);
		}
		return true;
	}
}

static bool checkValidInputLine(std::string line, std::string &key, double &value) {
	std::size_t pos = line.find("|");
	if (pos == std::string::npos || countOccurrences(line, '|') != 1) {
		throw std::runtime_error("bad input => " + line);
	}
	char* endPtr;
	key = line.substr(0, pos);
	value = strtod(line.substr(pos + 1).c_str(), &endPtr);
	if (value < 0) {
		throw std::runtime_error("not a positive number");
	}
	if (2147483647 < value) {
		throw std::runtime_error("too large a number.");
	}
	isValidDate(line, key);
	return true;
}

void BitcoinExchange::runInput(std::string fileName) const {
	std::ifstream outFile(fileName);
	if (!outFile.is_open()) {
		throw std::runtime_error("not open input file.");
	}
	std::string line;
	std::map<std::string, double>::const_iterator it;
	std::string key;
	double value, res;

	std::getline(outFile, line);
	if (checkValidFirstLine(line, "date | value")) {
		return throw std::runtime_error("invalid format file : date | value");
	}
	while (std::getline(outFile, line)) {
		try {
			checkValidInputLine(line, key, value);
			it = this->_bitcoinData.lower_bound(key);
			if (it == this->_bitcoinData.begin()) {
				throw std::runtime_error("invalid input => " + line);
			}
			--it;
			res = value * (it->second);
			if (2147483647 < res) {
				throw std::runtime_error("over value | max : 2147483647");
			}
			std::cout << key << "=> " << value << " = " << res << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
}

std::map<std::string, double> BitcoinExchange::getBitcoinData() const {
	return this->_bitcoinData;
}
