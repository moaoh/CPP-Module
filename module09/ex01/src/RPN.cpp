#include <iostream>
#include <string>

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &src) {
  this->_value = src._value;
  this->_oper = src._oper;
}

RPN &RPN::operator=(RPN const &rhs) {
  if (this == &rhs) {
    return *this;
  }
  this->_value = rhs._value;
  this->_oper = rhs._oper;
  return *this;
}

RPN::~RPN () {}

static void checkValidKey(std::string &key) {
  if (key.size() != 1) {
    throw std::runtime_error("Error");
  }
  const char *value[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "-", "/", "*"};
  bool isCheck = false;
  for (size_t i = 0; i < sizeof(value) / sizeof(value[0]); i++) {
    if (key == value[i]) {
      isCheck = true;
    }
  }
  if (!isCheck) {
    throw std::runtime_error("Error");
  }
}

void RPN::enqueueData(std::string &key) {
  const char *numbers[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
  const char *operList[] = {"+", "-", "/", "*"};

  for (size_t i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
    if (key == numbers[i]) {
      this->_value.push(std::atoi(key.c_str()));
      return ;
    }
  }
  for (size_t i = 0; i < sizeof(operList) / sizeof(operList[0]); i++) {
    if (key == operList[i]) {
      this->_oper.push(key);
      return ;
    }
  }
  throw std::runtime_error("Error");
}

std::queue<int> RPN::getValue() const {
  return this->_value;
}

std::queue<std::string> RPN::getOper() const {
  return this->_oper;
}

void RPN::printValue() const {
  std::queue<int> value = this->getValue();
  while (!value.empty()) {
      std::cout << "value :" << value.front() << std::endl;
      value.pop();
  }
}

void RPN::printOper() const {
  std::queue<std::string> oper = this->getOper();
  while (!oper.empty()) {
    std::cout << "operator :" << oper.front() << std::endl;
    oper.pop();
  }
}

void RPN::inData(std::string str) {
  while (true) {
    size_t pos = str.find(" ");
    std::string key = str.substr(0, pos);
    checkValidKey(key);
    enqueueData(key);
    if (pos == std::string::npos) {
      break;
    }
    str = str.substr(pos + 1);
  }
}

void RPN::run() {
  long long int sum = 0;
  std::string oper;
  int value;
  if (!this->_value.empty()) {
    sum = _value.front();
    this->_value.pop();
  }
  while (true) {
    if (!this->_oper.empty()) {
      oper = this->_oper.front();
      this->_oper.pop();
    } 
    else {
      break;
    }
    if (!this->_value.empty()) {
      value = this->_value.front();
      this->_value.pop();
    } 
    else {
      break;
    }
    if (oper == "+") {
      sum += value;
    } 
    else if (oper == "-") {
      sum -= value;
    } 
    else if (oper == "/") {
      sum /= value;
    } 
    else if (oper == "*") {
      sum *= value;
    }
  } 
  if (!this->_oper.empty() || !this->_value.empty()) {
    throw std::runtime_error("Error");
  } else {
    std::cout << sum << std::endl;
  }
}

// 1 2 2 2 2 4
// * / * - +