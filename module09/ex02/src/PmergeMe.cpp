#include <iostream>
#include <cctype>
#include <string>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &src) {
  this->_vector = src._vector;
  this->_deque = src._deque;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
  if (this == &rhs) return *this;
  this->_vector = rhs._vector;
  this->_deque = rhs._deque;
  return *this;
}

PmergeMe::~PmergeMe() {}

// 음수 불가능.
// 소수점이 존재하는 경우 불가능. ex O : 12.0 | X : 12.5
// ./PmergeMe 3 55 9 7 4 : O
// ./PmergeMe "3 55 9 7 4" : X
void PmergeMe::isValidData(const char *data) {
  char* endPtr;
  double doubleValue;
  const char* values[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "."};

  for (int i = 0; data[i] != '\0'; i++) {
    bool isChecker = false;
    for (size_t j = 0; j < sizeof(values) / sizeof(values[0]); j++) {
      if (data[i] == *values[j]) {
        isChecker = true;
      }
    }
    if (isChecker == false) {
      throw std::runtime_error("invalid value");
    }
  }
  doubleValue = std::strtod(data, &endPtr);
  if (endPtr == data) {
    throw std::runtime_error("invalid value");
  }
  if (doubleValue < 0 || 2147483647 < doubleValue) {
    throw std::runtime_error("invalid value");
  }
  std::strtol(data, &endPtr, 10);
  if (*endPtr == '.') {
    throw std::runtime_error("invalid value");
  }
}

void PmergeMe::inContainerData(int size, char **datalist)
{
  for (int i = 1; i < size; i++) {
    isValidData(datalist[i]);
  }
}

