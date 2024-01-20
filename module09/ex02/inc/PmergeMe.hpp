#ifndef PmergeMe_hpp_
#define PmergeMe_hpp_

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
public:
  PmergeMe();
  PmergeMe(PmergeMe const &src);
  PmergeMe &operator=(PmergeMe const &rhs);
  ~PmergeMe();

  void isValidData(std::string &data);
  void inContainerData(std::string const *dataList);
private:
    std::vector<int> _vec;
    std::deque<int> _de;
};

#endif
