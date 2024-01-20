#ifndef RPN_HPP_
#define RPN_HPP_

#include <iostream>
#include <queue>

class RPN  {
public:
  RPN();
  RPN(RPN const &src);
  RPN &operator=(RPN const &rhs);
  ~RPN();

  void inData(std::string str);
  void run();

  std::queue<int> getValue() const;
  std::queue<std::string> getOper() const;

  void printValue() const;
  void printOper() const;

private:
  std::queue<int> _value;
  std::queue<std::string> _oper;

  void enqueueData(std::string &key);
};

#endif // !RPN_HPP_
