#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int		value;
	static const int integer = 8;
public:
	Fixed();
	Fixed( const Fixed& fixed );
	~Fixed();
	int getRawBits() const;
};

#endif