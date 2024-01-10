#ifndef iter_hpp_
#define iter_hpp_

#include <iostream>

template <typename T, typename U>
void  iter(T *address, size_t len, U fun) {
  for (size_t i=0; i < len; i++) {
		fun(address[i]);
	}
}

template <typename T>
void print(T &str) {
	std::cout << str << std::endl;
}

#endif
