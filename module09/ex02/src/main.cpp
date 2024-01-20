#include "PmergeMe.hpp"

// 음수 불가능.
// 소수점이 존재하는 경우 불가능. ex O : 12.0 , X : 12.5
int     main(int ac, char **av) {
  try {
    if (ac < 2) {
      throw std::runtime_error("Invalid input.");
    }
    // isValidData : 유효성검사
    // first container loop (vector)
    // second container loop (deque)
    for (int i = 0; i < ac; i++) {
      std::cout << av[i] << std::endl;
    }
  }
  catch (const std::exception& e) { 
      std::cerr << e.what() << '\n';
  }
  return (0);
}