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

  void isValidData(const char *data);
  void inContainerData(int size, char **datalist);

  void fordJohsonVector();
  void fordJohsonDeque();

private:
    std::vector<int> _vector;
    std::deque<int> _deque;
};

#endif
