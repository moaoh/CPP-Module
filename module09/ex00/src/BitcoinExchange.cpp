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

static bool hasExtension(const char* fileName, const char* extension) {
	const char* dotPosition = std::strrchr(fileName, '.');
	if (dotPosition == nullptr || dotPosition == fileName || *(dotPosition + 1) == '\0') {
		return false;
	}
	const char* fileExtension = dotPosition + 1;
	return std::strcmp(fileExtension, extension) == 0;
}

void	BitcoinExchange::inBitcoinData() {
	std::ifstream outFile("data.csv");
	if (!outFile.is_open()) {
		throw std::runtime_error("not open file. : data.csv");
	}
	std::string line;
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

static bool isValidDate(std::string key) {
	if (countOccurrences(key, '-') != 2) {
		throw std::runtime_error("bad input => " + key);
	}
	int firstTarget = key.find("-");
	int secondTarget = key.rfind("-");
	int year = std::atoi(key.substr(0, firstTarget).c_str());
	int month = std::atoi(key.substr(firstTarget + 1, secondTarget).c_str());
	int day = std::atoi(key.substr(secondTarget + 1).c_str());
	const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year < 1000 || 10000 <= year || month < 1 || 12 < month || day < 1) {
		throw std::runtime_error("bad input => " + key);
	}
	if (month == 2 && isLeapYear(year)) {
		if (day < 1 || 29 < day) {
			throw std::runtime_error("bad input => " + key);
		}
		return true;
	}
	else {
		if (day < 1 || daysInMonth[month] < day) {
			throw std::runtime_error("bad input => " + key);
		}
		return true;
	}
}

// 양수만 가능.
// Error: not a positive number
// int 범위를 넘는경우 Cut!
// Error: too large a number.
// 입력 값이 잘못된 경우 Cut!
// Error: bad input => 2001-42-42
// time_value 
static bool checkValidInputLine(std::string line, std::string &key, double &value) {
	// TODO : date | value 형식따로 반례처리 필요.
	std::size_t pos = line.find("|");
	if (pos == std::string::npos || countOccurrences(line, '|') != 1) {
		throw std::runtime_error("bad input => " + key);
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
	isValidDate(key);
	return true;
}

// 확장자가 .txt인지 확인 필요. 
void BitcoinExchange::runInput(std::string fileName) const {
	std::ifstream outFile(fileName);
	if (!outFile.is_open()) {
		throw std::runtime_error("not open input file.");
	}
	if (!hasExtension(fileName.c_str(), "txt")) {
		throw std::runtime_error("not file extension : .txt");
	}
	std::string line;
	while (std::getline(outFile, line)) {
		try {
			std::map<std::string, double>::const_iterator it;
			std::string key;
			double value, res;

			checkValidInputLine(line, key, value);
			it = this->_bitcoinData.lower_bound(key);
			if (it == this->_bitcoinData.begin()) {
				throw std::runtime_error("invalid value");
			}
			--it;
			res = value * (it->second);
			std::cout << "value :" << value << std::endl;
			std::cout << "it->second :" << it->second << std::endl;
			std::cout << std::fixed << "res :" << res << std::endl;
			// TODO : 소수점 정리필요.
			if (2147483647 < res) {
				throw std::runtime_error("over value | max : 2147483647");
			}
			std::cout << std::fixed << key << "=> " << value << " = " << res << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
}

std::map<std::string, double> BitcoinExchange::getBitcoinData() const {
	return this->_bitcoinData;
}
