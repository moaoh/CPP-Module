#ifndef Span_hpp_
#define Span_hpp_

#include <iostream>
#include <vector>

class Span
{
private:
	unsigned int size_;
	std::vector <int> values_;
	Span();

public:
	Span(unsigned int n);
	Span(Span const &src);
	Span &operator=(Span const &rhs);
	~Span();

	unsigned int getSize() const;
	std::vector<int> const &getValues() const;

	void addNumber(int n);

	// 숫자가 1개 or null is error
	int shortestSpan() const;
	int longestSpan() const;

	class OutOfIndex : public std::exception {
	public:
		const char *what() const throw() {
			return ("Out of index");
		}
	};
	class FullException : public std::exception {
	public:
		const char *what() const throw() {
			return ("Full vectors");
		}
	};
};

#endif
