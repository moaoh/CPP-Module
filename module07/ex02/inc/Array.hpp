#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>

template <typename T>
class Array {
private:
	T	*array_;
	unsigned int arraySize_;

public:
	Array(void) : array_(NULL), arraySize_(0) {}

	Array(unsigned int arraySize) : array_(NULL), arraySize_(arraySize) {
		if (this->arraySize_ != 0) {
			this->array_ = new T[this->arraySize_];
		}
	}

	Array(const Array& src) : array_(NULL), arraySize_(src.arraySize_) {
		if (this->arraySize_ != 0) {
			this->array_ = new T[this->arraySize_];
		}
		for (unsigned int i = 0; i < this->arraySize_; i++) {
			this->array_[i] = src.array_[i];
		}
	}

	Array &operator=(const Array& rhs) {
		if (this == rhs) return *this;
		this->array_ = new T[this->arraySize_];
		for (unsigned int i = 0; i < this->arraySize_; i++) {
			this->array_[i] = rhs.array_[i];
		}
		return *this;
	}

	~Array() {
		delete[] this->array_;
	}

	class OutOfIndex : public std::exception {
	public:
		const char *what() const throw() {
			return "out of index!";
		}
	};

	T &operator[](unsigned int index) {
		if (index < 0 || this->arraySize_ - 1 < index) {
			throw OutOfIndex();
		}
		return this->array_[index];
	}

	T const &operator[](unsigned int index) const {
		if (index < 0 || this->arraySize_ - 1 < index) {
			throw OutOfIndex();
		}
		return this->array_[index];
	}

	T size() {
		return arraySize_;
	}
};

#endif
