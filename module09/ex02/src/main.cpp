#include <iostream>

#include "PmergeMe.hpp"


int     main(int ac, char **av) {
  try {
    if (ac < 2) {
      throw std::runtime_error("Invalid input.");
    }
    std::vector<int>	vecOriginalData;
	std::vector<int>	vecData;
	std::deque<int>		deData;

	vecOriginalData = inContainerData<std::vector<int> >(ac - 1, av + 1);
	vecData.assign(vecOriginalData.begin(), vecOriginalData.end());
	deData.assign(vecOriginalData.begin(), vecOriginalData.end());

	std::cout << "Before: ";
	show(vecOriginalData);
	double elapsedVec = sort(vecData);
	double elapsedDe = sort(deData);
	std::cout << "After: ";
	show(vecData);

	sentenceOutput(vecData.size(), "std::vector<int>", elapsedVec);
	sentenceOutput(deData.size(), "std::deque<int>", elapsedDe);
  }
  catch (const std::exception& e) { 
    std::cerr << "Error: " << e.what() << '\n';
  }
  return (0);
}
