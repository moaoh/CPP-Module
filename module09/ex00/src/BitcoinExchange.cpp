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

// 양수만 가능.
// Error: not a positive number
// int 범위를 넘는경우 Cut!
// Error: too large a number.
// 입력 값이 잘못된 경우 Cut!
// Error: bad input => 2001-42-42
static bool checkValidInputLine(double value) {
	if (value < 0) {
		throw std::runtime_error("not a positive number");
	}
	if (2147483647 < value || value < -2147483647) {
		throw std::runtime_error("too large a number.");
	}
	return true;
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
			std::size_t pos = line.find("|");
			if (pos == std::string::npos || countOccurrences(line, '|') != 1) {
				throw std::runtime_error("bad input => " + line);
			}
			char* endPtr;
			std::string key = line.substr(0, pos);
			double value = strtod(line.substr(pos + 1).c_str(), &endPtr);
			checkValidInputLine(value);
			std::map<std::string, double>::const_iterator it;
			it = this->_bitcoinData.lower_bound(key);
			if (it == this->_bitcoinData.begin() || it == this->_bitcoinData.end()) {
				throw std::runtime_error("invalid value");
			}
			--it;
			std::cout << key << "=> " << value << " = " << value * it->second << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
}

std::map<std::string, double> BitcoinExchange::getBitcoinData() const {
	return this->_bitcoinData;
}