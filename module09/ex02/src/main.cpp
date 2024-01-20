#include <iostream>

#include "PmergeMe.hpp"

// 음수 불가능.
// 소수점이 존재하는 경우 불가능. ex O : 12.0 | X : 12.5
int     main(int ac, char **av) {
  std::string *stringArray = new std::string[ac];
  try {
    if (ac < 2) {
      throw std::runtime_error("Invalid input.");
    }
    std::string *stringArray = new std::string[ac];
    for (int i = 0; i < ac - 1; i++) {
      stringArray[i] = av[i + 1];
    }
    // isValidData : 유효성검사 및 각각 container에 저장.
    PmergeMe me;
    me.inContainerData(stringArray);
    // first container loop (vector)
    // second container loop (deque)
  }
  catch (const std::exception& e) { 
      std::cerr << e.what() << '\n';
  }
  delete[] stringArray;
  return (0);
}