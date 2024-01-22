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

  void mergeInsertion() const;
  void mergeInsertionVector() const;
  void mergeInsertionDeque() const;

  void inVectorOriginalData(const char *data);

  std::vector<int> const getVectorData() const;
  std::deque<int> const getDequeData() const;

  void printVectorData() const;
  void printDequeData() const;
  void printVectorOriginalData() const;

private:
  std::vector<int> _vectorOriginalData;
  std::vector<int> _vectorData;
  std::deque<int> _dequeData;
};

#endif
