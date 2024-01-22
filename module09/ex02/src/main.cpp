#include <iostream>

#include "PmergeMe.hpp"


int     main(int ac, char **av) {
  try {
    if (ac < 2) {
      throw std::runtime_error("Invalid input.");
    }
    PmergeMe pmerg;
    pmerg.inContainerData(ac, av);
    // isValidData : 유효성검사 및 각각 container에 저장.
    // first container loop (vector)
    // second container loop (deque)
  }
  catch (const std::exception& e) { 
      std::cerr << "Error: " << e.what() << '\n';
  }
  return (0);
}