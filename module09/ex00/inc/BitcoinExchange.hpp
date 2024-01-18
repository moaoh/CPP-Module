#ifndef BitcoinExchange_hpp_
#define BitcoinExchange_hpp_

#include <iostream>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, double> _bitcoinData;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange &operator=(const BitcoinExchange& rhs);
	~BitcoinExchange();

	// bitcoin의 정보를 map에 보관할 함수
	void inBitcoinData();
	std::map<std::string, double> getBitcoinData() const;
	void runBuyList(std::string fileName) const;
};

#endif
