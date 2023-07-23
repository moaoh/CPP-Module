#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					value;
	static const int	integer = 8;
public:
	Fixed();
	Fixed( const Fixed& fixed );
	Fixed( const int raw );
	Fixed( const float raw );
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

	Fixed &operator = ( const Fixed& fixed );

	~Fixed();
};

std::ostream &operator << (std::ostream& os, const Fixed& fixed);

#endif