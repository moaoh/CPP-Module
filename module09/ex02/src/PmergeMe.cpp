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
    throw std::overflow_error("invalid value");
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

static void binarySearch(std::deque< std::deque<int> >& arr, std::deque<int> temp) {
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

static void binarySearch(std::vector< std::vector<int> >& arr, std::vector<int> temp) {
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

template <typename container>
static void moveLargestToFirst(container& vec) {
    if (vec.empty()) {
        // 벡터가 비어있으면 아무것도 할 필요가 없음
        return;
    }

    // 가장 큰 값을 찾기 위한 반복문
    size_t indexOfLargest = 0;
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > vec[indexOfLargest]) {
            indexOfLargest = i;
        }
    }

    // 가장 큰 값을 [0] 위치로 이동
    if (indexOfLargest != 0) {
        std::swap(vec[0], vec[indexOfLargest]);
    }
}

void mergeInsertion(std::vector<int> &arr, int nodeSize) {
  if ((arr.size() / nodeSize) < 2) {
    return ;
  }
  int arrSize = arr.size();
  std::vector<int> tempVec;
  if (arr.size() % nodeSize != 0) {
    int restValueSize = (arr.size() % nodeSize);
    tempVec.insert(tempVec.begin(), arr.end() - restValueSize, arr.end());
    arrSize = arrSize - restValueSize;
  }

  // nodeSize 개수 씩 묶어 groupedVec에 저장.
  std::vector<std::vector<int> > groupedVec;
  for (int i = 0; i < arrSize; i += nodeSize) {
    std::vector<int> group(arr.begin() + i, arr.begin() + std::min(i + nodeSize, arrSize));
    groupedVec.push_back(group);
  }
  for (size_t i = 0; i < groupedVec.size(); i++) {
    moveLargestToFirst<std::vector<int> >(groupedVec[i]);
  }

  // groupedVec들을 pair로 바꾸어 저장할 누군가가 필요.
  std::vector<std::vector<int> > remainerVec;
  if (groupedVec.size() % 2 != 0) {
    remainerVec.push_back(groupedVec.back());
    groupedVec.pop_back();
  }
  std::vector<std::pair<std::vector<int>, std::vector<int> > > pairList;
  for (size_t i = 0; i < groupedVec.size(); i += 2) {
    pairList.push_back(std::make_pair(groupedVec[i], groupedVec[i + 1]));
  }

  // 큰 수 기준으로 정렬.
  // pair들중 큰 값을 first로 변경.
  for(size_t i = 0; i < pairList.size(); i++) {
    if (pairList[i].first.front() < pairList[i].second.front()) {
      std::swap(pairList[i].first, pairList[i].second);
    }
  }

  // pairList front중 큰값을 기준으로 정렬
  // 일단 보류 (로직이 맞는지 확인 못함.)
  for(size_t i = 1; i < pairList.size(); i++) {
    std::vector<int> key = pairList[i].first;
    size_t j = i;
    while (0 < j && pairList[j - 1].first.front() > key.front()) {
      pairList[j] = pairList[j - 1];
      j--;
    }
    pairList[j].first = key;
  }
  
  std::vector<std::vector<int> > win;
  std::vector<std::vector<int> > lose;
  for (size_t i = 0; i < pairList.size(); i++) {
    win.push_back(pairList[i].first);
    lose.push_back(pairList[i].second);
  }
  if (!remainerVec.empty()) {
    lose.push_back(remainerVec.back());
    remainerVec.pop_back();
  }

  std::vector<size_t> jacobsthalArr = getJacobsthal<std::vector<size_t> >(arrSize);
  for (size_t i = 1; i < jacobsthalArr.size(); i++) {
    int max = std::min(jacobsthalArr[i], lose.size());
    int min = jacobsthalArr[i - 1];
    for (int j = max - 1; j >= min; j--) {
      binarySearch(win, lose[j]);
    }
  }

  if (!tempVec.empty()) {
    binarySearch(win, tempVec);
  }

  std::vector<int>::iterator iter = arr.begin();
  for (size_t i = 0; i < win.size(); i++) {
    for (size_t j = 0; j < win[i].size(); j++) {
      *iter = win[i][j];
      ++iter;
    }
  }
}

void mergeInsertion(std::deque<int> &arr, int nodeSize) {
  if ((arr.size() / nodeSize) < 2) {
    return ;
  }
  int arrSize = arr.size();
  std::deque<int> tempVec;
  if (arr.size() % nodeSize != 0) {
    int restValueSize = (arr.size() % nodeSize);
    tempVec.insert(tempVec.begin(), arr.end() - restValueSize, arr.end());
    arrSize = arrSize - restValueSize;
  }

  // nodeSize 개수 씩 묶어 groupedVec에 저장.
  std::deque<std::deque<int> > groupedVec;
  for (int i = 0; i < arrSize; i += nodeSize) {
    std::deque<int> group(arr.begin() + i, arr.begin() + std::min(i + nodeSize, arrSize));
    groupedVec.push_back(group);
  }
  for (size_t i = 0; i < groupedVec.size(); i++) {
    moveLargestToFirst<std::deque<int> >(groupedVec[i]);
  }

  // groupedVec들을 pair로 바꾸어 저장할 누군가가 필요.
  std::deque<std::deque<int> > remainerVec;
  if (groupedVec.size() % 2 != 0) {
    remainerVec.push_back(groupedVec.back());
    groupedVec.pop_back();
  }
  std::deque<std::pair<std::deque<int>, std::deque<int> > > pairList;
  for (size_t i = 0; i < groupedVec.size(); i += 2) {
    pairList.push_back(std::make_pair(groupedVec[i], groupedVec[i + 1]));
  }
  
  // 큰 수 기준으로 정렬.
  // pair들중 큰 값을 first로 변경.
  for(size_t i = 0; i < pairList.size(); i++) {
    if (pairList[i].first.front() < pairList[i].second.front()) {
      std::swap(pairList[i].first, pairList[i].second);
    }
  }

  // pairList front중 큰값을 기준으로 정렬
  // 일단 보류 (로직이 맞는지 확인 못함.)
  for(size_t i = 1; i < pairList.size(); i++) {
    std::deque<int> key = pairList[i].first;
    size_t j = i;
    while (0 < j && pairList[j - 1].first.front() > key.front()) {
      pairList[j] = pairList[j - 1];
      j--;
    }
    pairList[j].first = key;
  }
  
  std::deque<std::deque<int> > win;
  std::deque<std::deque<int> > lose;
  for (size_t i = 0; i < pairList.size(); i++) {
    win.push_back(pairList[i].first);
    lose.push_back(pairList[i].second);
  }
  if (!remainerVec.empty()) {
    lose.push_back(remainerVec.back());
    remainerVec.pop_back();
  }

  std::deque<size_t> jacobsthalArr = getJacobsthal<std::deque<size_t> >(arrSize);
  for (size_t i = 1; i < jacobsthalArr.size(); i++) {
    int max = std::min(jacobsthalArr[i], lose.size());
    int min = jacobsthalArr[i - 1];
    for (int j = max - 1; j >= min; j--) {
      binarySearch(win, lose[j]);
    }
  }

  if (!tempVec.empty()) {
    binarySearch(win, tempVec);
  }

  std::deque<int>::iterator iter = arr.begin();
  for (size_t i = 0; i < win.size(); i++) {
    for (size_t j = 0; j < win[i].size(); j++) {
      *iter = win[i][j];
      ++iter;
    }
  }
}

void mergeInsertionSort(std::vector<int> &arr, int depth, int nodeSize) {
  mergeInsertion(arr, nodeSize);
  if (depth <= 1) {
    return ;
  }
  mergeInsertionSort(arr, depth - 1, nodeSize / 2);
}

void mergeInsertionSort(std::deque<int> &arr, int depth, int nodeSize) {
  mergeInsertion(arr, nodeSize); 
  if (depth <= 1) {
    return ;
  }
  mergeInsertionSort(arr, depth - 1, nodeSize / 2);
}

void sentenceOutput(size_t size, std::string type, double elapsed) {
  std::cout \
    << std::fixed << "Time to process a range of " \
    << size << " elements with " << type << " : " \
    << elapsed << " us" << std::endl;
}
