#include <iostream>
#include <string>
#include <vector>

#include "easyfind.hpp"

int main(void) {

	int	intArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int size = sizeof(intArr) / sizeof(int);
	std::vector<int> vec(intArr, intArr + size);
	try {
		std::cout << *easyfind(vec, 4) << std::endl;
		std::cout << *easyfind(vec, 42) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return (0);
}
