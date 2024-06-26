#include <iostream>
#include <fstream>
#include <string>

#include "BitcoinExchange.hpp"

int	main(int ac, char** av) {
	try {
		if (ac != 2) {
			throw std::runtime_error("could not open file.");
		}
		BitcoinExchange bitcoin;
		bitcoin.inBitcoinData();
		bitcoin.runInput(av[1]);
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	return (0);
}
