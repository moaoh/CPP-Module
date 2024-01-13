#ifndef Span_hpp_
#define Span_hpp_

#include <iostream>
#include <vector>

class Span
{
private:
	unsigned int _size;
	std::vector <int> _values;
	Span();

public:
	Span(unsigned int n);
	Span(Span const &src);
	Span &operator=(Span const &rhs);
	~Span();

	unsigned int size() const;
	std::vector<int> const &getValues() const;

	void addNumber(int n);
	void addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);

	int shortestSpan() const;
	int longestSpan() const;

	class FullException : public std::exception {
	public:
		const char *what() const throw() {
			return ("vector is full.");
		}
	};
	class CantSearchException : public std::exception {
	public:
		const char *what() const throw() {
			return ("can't Search.");
		}
	};
};

#endif
