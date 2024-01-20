#include <iostream>

#include "RPN.hpp"

int main(int ac, char **av)
{
  try {
    if (ac != 2) {
			throw std::runtime_error("could not text.");
    }
    RPN rpn;
    rpn.calculateRPN(av[1]);
    std::cout << rpn.getSum() << std::endl;
  }
  catch (const std::exception& e) { 
	  std::cerr << e.what() << '\n';
  }
  return (0);
}
