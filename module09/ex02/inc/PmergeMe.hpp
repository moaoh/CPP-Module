#ifndef PmergeMe_hpp_
#define PmergeMe_hpp_

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

int isValidData(const char *data);

void mergeInsertion(std::vector<int> &, int low, int hgih);
void mergeInsertion(std::deque<int> &);

void mergeInsertionSort(std::vector<int> &, int low, int high);
void mergeInsertionSort(std::deque<int> &, int low, int high);


template <typename Container>
double sort(Container &container) {
  if (container.size() == 1) {
    return 0;
  }
  clock_t startTime = clock();
  mergeInsertionSort(container, 0, container.size() - 1);
  clock_t endTime = clock();
  double elapsedTime = static_cast<double>(endTime - startTime) * 1000000 / CLOCKS_PER_SEC;
  return (elapsedTime);
}

void sentenceOutput(size_t size, std::string type, double elapsed);

template <typename Container>
Container inContainerData(int size, char **datalist) {

  Container Data;
  for (int i = 0; i < size; i++) {
    Data.push_back(isValidData(datalist[i]));
  }
  return (Data);
}

template <typename T>
void show(const T& container) {
  typename T::const_iterator  it;
  for (it = container.begin(); it != container.end(); it++) {
		if (it != container.begin()) {
			std::cout << " ";
    }
		std::cout << *it;
  }
  std::cout << std::endl;
}

#endif
