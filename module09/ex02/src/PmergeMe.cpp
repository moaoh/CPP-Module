#include <iostream>
#include <cctype>
#include <string>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &src) {
  this->_vec = src._vec;
  this->_de = src._de;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
  if (this == &rhs) return *this;
  this->_vec = rhs._vec;
  this->_de = rhs._de;
  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::isValidData(std::string &data) {
  (void)data;
}

void PmergeMe::inContainerData(std::string const *dataList) {
  for (size_t i = 0; i < dataList->size(); i++) {
    std::cout << dataList[i] << std::endl;
  }
  // for (int i = 0; i < len; i++) {
  //   isValidData(std::string(dataList[i]));
  // }
}

