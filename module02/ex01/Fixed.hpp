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
	~Fixed();
	Fixed( const Fixed& fixed );

	Fixed( const int _value );
	Fixed( const float _value );

	int getRawBits() const;
	void setRawBits( int const raw );
	Fixed &operator=(const Fixed &other);

	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif