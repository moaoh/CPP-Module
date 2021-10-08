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
	Fixed( const int value );
	Fixed( const float value );

	int getRawBits() const;
	void setRawBits( int const raw );

	Fixed &operator = ( const Fixed &other );

	bool operator > ( const Fixed &other );
	bool operator < ( const Fixed &other );
	bool operator >= ( const Fixed &other );
	bool operator <= ( const Fixed &other );
	bool operator == ( const Fixed &other );
	bool operator != ( const Fixed &other );

	Fixed operator + ( const Fixed &other );
	Fixed operator - ( const Fixed &other );
	Fixed operator * ( const Fixed &other );
	Fixed operator / ( const Fixed &other );

	Fixed operator ++ ( void );

	float toFloat( void ) const;
	int toInt( void ) const;

	~Fixed();
};

std::ostream& operator << (std::ostream &os, const Fixed &fixed);

#endif