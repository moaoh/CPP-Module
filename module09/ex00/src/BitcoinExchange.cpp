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
		std::string key = line.substr(0, pos);
		char* endPtr;
		double value = strtod(line.substr(pos + 1).c_str(), &endPtr);
		this->_bitcoinData.insert(std::make_pair(key, value));
	}
}

std::map<std::string, double> BitcoinExchange::getBitcoinData() const {
	return this->_bitcoinData;
}

static bool hasExtension(const char* fileName, const char* extension) {
	const char* dotPosition = std::strrchr(fileName, '.');
	if (dotPosition == nullptr || dotPosition == fileName || *(dotPosition + 1) == '\0') {
		return false;
	}
	const char* fileExtension = dotPosition + 1;
	return std::strcmp(fileExtension, extension) == 0;
}

// 확장자가 .txt인지 확인 필요. 
void BitcoinExchange::runBuyList(std::string fileName) const {
	std::cout << "Run Run" << std::endl;
	std::ifstream outFile(fileName);
	if (!outFile.is_open()) {
		throw std::runtime_error("not open file. BuyList");
	}
	if (!hasExtension(fileName.c_str(), "txt")) {
		throw std::runtime_error("not file extension : .txt");
	}
	std::string line;
	while (std::getline(outFile, line)) {
		std::cout << line << std::endl;
	}
	// std::map<std::string, double>::iterator temp = std::upper_bound(this->_bitcoinData.begin(), this->_bitcoinData.end());
	// std::cout << *temp << std::endl;
}
