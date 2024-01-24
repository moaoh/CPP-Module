#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

#include "PmergeMe.hpp"

// 음수 불가능.
// 소수점이 존재하는 경우 불가능. ex | X : 12.5
// ./PmergeMe 3 55 9 7 4 : O
// ./PmergeMe "3 55 9 7 4" : X
int isValidData(const char *data) {
  char* endPtr;
  long long llValue;

  llValue = std::strtol(data, &endPtr, 10);
  if (endPtr != NULL && *endPtr != '\0') {
    throw std::invalid_argument("invalid value");
  }
  if (llValue < 0 || std::numeric_limits<int>::max() < llValue) {
    throw std::overflow_error("over value");
  }
  return std::atoi(data);
}

template <typename container>
static container getJacobsthal(size_t size) {
  container jacobsthalArr;

  jacobsthalArr.push_back(0);
  jacobsthalArr.push_back(1);
  for (size_t i = 2; ; i++) {
    size_t num = jacobsthalArr[i - 1] + (jacobsthalArr[i - 2] * 2);
    if (size < num) {
      return jacobsthalArr;
    }
    jacobsthalArr.push_back(num); 
  }
}

template <typename container>
static void binarySearch(container& arr, int temp) {
  int low = 0;
  int high = arr.size() - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (temp < arr[mid]) {
      high = mid - 1;
    }
    else if (temp >= arr[mid]) {
      low = mid + 1;
    }
  }
  arr.insert(arr.begin() + low, temp);
}

void mergeInsertion(std::vector<int> &arr, int low, int high) {
  int temp = 0;

  std::cout << "arr.size() :" << arr.size() << std::endl;
  for (int i = low; i < high; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
  // 홀수면 남는 값 따로 뺴기.
  if ((high - low) % 2 != 0) {
    temp = arr[high + 1];
    high--;
  }
  
  // 2개씩 묶어서 pair에 저장.
  std::vector<std::pair<int, int> > pairList;
  for (int i = low; i < high; i += 2) {
    pairList.push_back(std::make_pair(arr[i], arr[i + 1]));
  }


  // pair중 큰 수를 first로.
  for (size_t i = 0; i < pairList.size(); i++) {
    if (pairList[i].first < pairList[i].second) {
      std::swap(pairList[i].first, pairList[i].second);
    }
  }

  // 큰 수 기준으로 정렬.
  for(size_t i = 1; i < pairList.size(); i++) {
    std::pair<int, int> key = pairList[i];
    size_t j = i;
    while (0 < j && pairList[j - 1] > key) {
      pairList[j] = pairList[j - 1];
      j--;
    }
    pairList[j] = key;
  }


  std::vector<int> win;
  std::vector<int> lose;
  for (size_t i = 0; i < pairList.size(); i++) {
    win.push_back(pairList[i].first);
    lose.push_back(pairList[i].second);
  }

  std::vector<size_t> jacobsthalArr = getJacobsthal<std::vector<size_t> >(arr.size() + 1);
  for (size_t i = 1; i < jacobsthalArr.size(); i++) {
    int max = std::min(jacobsthalArr[i], lose.size());
    int min = jacobsthalArr[i - 1];
    for (int j = max - 1; j >= min; j--) {
      binarySearch(win, lose[j]);
    }
  }

  if (temp != 0) {
    binarySearch(win, temp);
  }

  std::cout << "win : ";
  for (size_t i = 0; i < win.size(); i++) {
    std::cout << win[i] << " ";
  }
  std::cout << std::endl;

  std::vector<int>::iterator iter = arr.begin() + low;
  for (std::vector<int>::iterator winIter = win.begin(); winIter != win.end(); winIter++) {
    *iter = *winIter;
    *iter++;
  }
}

void mergeInsertion(std::deque<int> &arr, int low, int high) {
  int temp = 0;

  // 홀수면 남는 값 따로 뺴기.
  if ((high - low) % 2 != 0) {
    temp = arr[high + 1];
    high--;
  }
  
  // 2개씩 묶어서 pair에 저장.
  std::deque<std::pair<int, int> > pairList;
  for (int i = low; i < high; i += 2) {
    pairList.push_back(std::make_pair(arr[i], arr[i + 1]));
  }

  // pair중 큰 수를 first로.
  for (size_t i = 0; i < pairList.size(); i++) {
    if (pairList[i].first < pairList[i].second) {
      std::swap(pairList[i].first, pairList[i].second);
    }
  }

  // 큰 수 기준으로 정렬.
  for(size_t i = 1; i < pairList.size(); i++) {
    std::pair<int, int> key = pairList[i];
    size_t j = i;
    while (0 < j && pairList[j - 1] > key) {
      pairList[j] = pairList[j - 1];
      j--;
    }
    pairList[j] = key;
  }

  std::deque<int> win;
  std::deque<int> lose;
  for (size_t i = 0; i < pairList.size(); i++) {
    win.push_back(pairList[i].first);
    lose.push_back(pairList[i].second);
  }

  // binary search part.
  std::deque<size_t> jacobsthalArr = getJacobsthal<std::deque<size_t> >(arr.size() + 1);
  for (size_t i = 1; i < jacobsthalArr.size(); i++) {
    int max = std::min(jacobsthalArr[i], lose.size());
    int min = jacobsthalArr[i - 1];
    for (int j = max - 1; j >= min; j--) {
      binarySearch(win, lose[j]);
    }
  }
  if (temp != 0) {
    binarySearch(win, temp);
  }
  
  std::deque<int>::iterator iter = arr.begin() + low;
  for (std::deque<int>::iterator winIter = win.begin(); winIter != win.end(); winIter++) {
    *iter = *winIter;
    *iter++;
  }
}

template <typename container>
static void mergeSort(container &arr, int low, int mid, int high) {
  int n1 = mid - low + 1;
  int n2 = high - mid;

  container left(n1);
  container right(n2);
  
  for (int i = 0; i < n1; i++) {
    left[i] = arr[low + i];
  }
  for (int i = 0; i < n2; i++) {
    right[i] = arr[mid + 1 + i];
  }

  int i = 0;
  int j = 0;
  int k = low;

  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = left[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = right[j];
    j++;
    k++;
  }
}

void mergeInsertionSort(std::vector<int> &arr, int low, int high)
{
  if (2 <= high - low + 1) {
    mergeInsertion(arr, low, high);
  } 
  else if (low < high) {
    int mid = (low + high) / 2;
    mergeInsertionSort(arr, low, mid);
    mergeInsertionSort(arr, mid + 1, high);
    mergeSort(arr, low, mid, high);
  }
}

void mergeInsertionSort(std::deque<int> &arr, int low, int high)
{
  if (2 <= high - low + 1) {
    mergeInsertion(arr, low, high);
  } 
  else if (low < high) {
    int mid = (low + high) / 2;
    mergeInsertionSort(arr, low, mid);
    mergeInsertionSort(arr, mid + 1, high);
    mergeSort(arr, low, mid, high);
  }
}

void sentenceOutput(size_t size, std::string type, double elapsed) {
  std::cout \
    << std::fixed << "Time to process a range of " \
    << size << " elements with " << type << " : " \
    << elapsed << " us" << std::endl;
}
