#include "Span.hpp"

Span::Span() {};

Span::Span(unsigned int n) : size_(n) {}

Span::Span(Span const &src) {
	this->size_ = src.size_;
	this->values_ = src.values_;
}

Span &Span::operator=(Span const &rhs) {
	if (this == &rhs) return *this;
	this->size_ = rhs.size_;
	this->values_ = rhs.values_;
	return *this;
}

Span::~Span() {}

unsigned int Span::getSize() const {
	return this->size_;
}

std::vector<int> const &Span::getValues() const {
	return this->values_;
}

void Span::addNumber(int n) {
	if (this->values_.size() >= this->size_) {
		throw FullException();
	}
	this->values_.push_back(n);
}


// 숫자가 1개 or null is error
// 인접한 두수의 차이가 가장 작은것
int Span::shortestSpan() const {
	if (this->values_.size() < 2) {
		throw std::logic_error("");
	}
	std::vector <int> copy = this->values_;
	std::sort(copy.begin(), copy.end());
	// TODO
	return (1);
}

// 인접한 두수의 차이가 가장 큰거
int Span::longestSpan() const {
	if (this->values_.size() < 2) {
		throw std::logic_error("");
	}
	std::vector <int> copy = this->values_;
	std::sort(copy.begin(), copy.end());
	// TODO
	return (1);
}

