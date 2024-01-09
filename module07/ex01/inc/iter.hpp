#ifndef iter_hpp_
#define iter_hpp_

#include <iostream>

template <typename T>
void  iter(T *address, size_t len, void(*fun)(T& t)) {
  for (size_t i=0; i < len ; i++) {
		fun(address[i]);
	}
}

template <typename T>
void  iter(T *address, size_t len, void(*fun)(T const& t)) {
  for (size_t i=0; i < len ; i++) {
		fun(address[i]);
	}
}

#endif
