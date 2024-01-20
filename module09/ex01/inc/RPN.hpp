#ifndef RPN_HPP_
#define RPN_HPP_

#include <iostream>
#include <stack>

class RPN  {
public:
  RPN();
  RPN(RPN const &src);
  RPN &operator=(RPN const &rhs);
  ~RPN();

  void calculateRPN(std::string str);

  std::stack<int> getValues() const;
  long long int getSum() const;
  void printValues() const;

private:
  std::stack<int> _values;
  long long int _sum;

  void runStack(std::string &key);
  int topPopValues();
};

#endif // !RPN_HPP_
