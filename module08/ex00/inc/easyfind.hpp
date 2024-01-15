#ifndef easyfind_hpp_
#define easyfind_hpp_

#include <iostream>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw std::runtime_error("no value in container");
	}
	return it;
}

#endif
