#include <iostream>

#include "RPN.hpp"

int main(int ac, char **av)
{
  try {
    if (ac != 2) {
			throw std::runtime_error("could not text.");
    }
    RPN rpn;
    rpn.inData(av[1]);
    rpn.run();
  }
  catch (const std::exception& e) { 
	  std::cerr << e.what() << '\n';
  }
  return (0);
}
