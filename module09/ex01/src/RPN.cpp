#include <iostream>
#include <string>

#include "RPN.hpp"

RPN::RPN() : _sum(0) {}

RPN::RPN(RPN const &src) {
  this->_values = src._values;
  this->_sum = src._sum;
}

RPN &RPN::operator=(RPN const &rhs) {
  if (this == &rhs) {
    return *this;
  }
  this->_values = rhs._values;
  this->_sum = rhs._sum;
  return *this;
}

RPN::~RPN () {}

static bool checkValidNum(std::string &key) {
  const char *numbers[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
  for (size_t i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
    if (key == numbers[i]) {
      return true;
    }
  }
  return false;
}

static bool checkValidOper(std::string &key) {
  const char *operList[] = {"+", "-", "/", "*"};
  for (size_t i = 0; i < sizeof(operList) / sizeof(operList[0]); i++) {
    if (key == operList[i]) {
      return true;
    }
  }
  return false;
}

static void checkValidKey(std::string &key) {
  if (key.size() != 1) {
    throw std::runtime_error("Error");
  }
  if (checkValidNum(key) == false && checkValidOper(key) == false) {
    throw std::runtime_error("Error");
  }
}

int RPN::topPopValues() {
  int tmp = this->_values.top();
  this->_values.pop();
  return tmp;
}

void RPN::runStack(std::string &key) {
  if (checkValidOper(key)) {
    if (this->_values.size() < 2) {
      throw std::runtime_error("Error");
    }
    long long int tmp1 = topPopValues();
    long long int tmp2 = topPopValues();
    long long int sum = 0;
    if (key == "+") {
      sum = tmp2 + tmp1;
    } 
    else if (key == "-") {
      sum = tmp2 - tmp1;
    } 
    else if (key == "/") {
      sum = tmp2 / tmp1;
    } 
    else if (key == "*") {
      sum = tmp2 * tmp1;
    }
    std::cout << "sum :" << sum << std::endl;
    if (sum < -2147483647 || 2147483647 < sum) {
      throw std::runtime_error("Error");
    }
    this->_values.push(sum);
  }
  else if (checkValidNum(key)) {
    this->_values.push(std::atoi(key.c_str()));
  }
  else {
    throw std::runtime_error("Error");
  }
}

std::stack<int> RPN::getValues() const {
  return this->_values;
}

long long int RPN::getSum() const {
  return this->_sum;
}

void RPN::printValues() const {
  std::stack<int> values = this->getValues();
  while (!values.empty()) {
      std::cout << "value :" << values.top() << std::endl;
      values.pop();
  }
}

void RPN::calculateRPN(std::string str) {
  while (true) {
    size_t pos = str.find(" ");
    std::string key = str.substr(0, pos);
    checkValidKey(key);
    runStack(key);
    if (pos == std::string::npos) {
      break;
    }
    str = str.substr(pos + 1);
  }
  if (this->_values.size() != 1) {
    throw std::runtime_error("Error");
  }
  this->_sum = topPopValues();
}