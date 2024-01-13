#include "Span.hpp"

Span::Span() {};

Span::Span(unsigned int n) : _size(n) {}

Span::Span(Span const &src) {
	this->_size = src._size;
	this->_values = src._values;
}

Span &Span::operator=(Span const &rhs) {
	if (this == &rhs) return *this;
	this->_size = rhs._size;
	this->_values = rhs._values;
	return *this;
}

Span::~Span() {}

unsigned int Span::size() const {
	return this->_size;
}

std::vector<int> const &Span::getValues() const {
	return this->_values;
}

void Span::addNumber(int n) {
	if (this->_values.size() >= this->_size) {
		throw FullException();
	}
	this->_values.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end) {
	unsigned int size = std::distance(begin, end);
	if (size > _size)
		throw Span::FullException();
	_values.insert(_values.end(), begin, end);
}

// 숫자가 1개 or null is error
// 인접한 두수의 차이가 가장 작은것
int Span::shortestSpan() const {
	if (this->_values.size() < 2) {
		throw CantSearchException();
	}
	std::vector <int> copy = this->_values;
	std::sort(copy.begin(), copy.end());
	int min = copy[copy.size() - 1] - copy[copy.size() - 2];
	for (int i = copy.size() - 1; i > 0; i--) {
		if (copy[i] - copy[i - 1] < min) {
			min = copy[i] - copy[i - 1];
		}
	}
	return (min);
}

// 인접한 두수의 차이가 가장 큰거
int Span::longestSpan() const {
	if (this->_values.size() < 2) {
		throw CantSearchException();
	}
	std::vector <int> copy = this->_values;
	std::sort(copy.begin(), copy.end());
	return (copy[copy.size() - 1] - copy[0]);
}

