#include <iostream>

#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "===== Exception test =====" << std::endl;
	{

		Span sp = Span(5);
		std::cout << "===== shortestSpan Exception =====" << std::endl;
		try {
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		std::cout << "===== longestSpan Exception =====" << std::endl;
		try {
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		std::cout << "===== addNumber Exception =====" << std::endl;
		try {
			for (int i = 0; i < 10; i++) {
				sp.addNumber(i);
			}
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "===== Span in one call. =====" << std::endl;
	{
		Span sp = Span(10000);
		std::vector<int> vec;
		for (int i = 1; i <= 10000; i++) {
			vec.push_back(i);
		}
		sp.addNumber(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	return 0;
}
/*
	$> ./ex01
	2
	14
	$>
*/
