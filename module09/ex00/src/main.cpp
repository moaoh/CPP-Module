#include <iostream>
#include <fstream>
#include <string>

#include "BitcoinExchange.hpp"

int	main(int ac, char** av) {
	try {
		if (ac != 2) {
			throw std::runtime_error("could not open file.");
		}
		(void)av;
		BitcoinExchange bitcoin;
		bitcoin.inBitcoinData();
		bitcoin.runBuyList(av[1]);
		// std::map<std::string, double> temp = bitcoin.getBitcoinData();
  //   for (std::map<std::string, double>::iterator it = temp.begin(); it != temp.end(); it++) {
  //       std::cout << "Key: " << it->first << std::fixed << ", Value: " << it->second << std::endl;
  //   }
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	return (0);
}
