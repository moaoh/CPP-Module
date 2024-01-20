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
private:
    std::vector<int> _vec;
    std::deque<int> _de;
};

#endif