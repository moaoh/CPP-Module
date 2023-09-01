#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed( const Fixed& fixed )
{
	*this = fixed;
}

Fixed::Fixed( const int raw )
{
	this->value = (raw << integer);
}

Fixed::Fixed( const float raw )
{
	this->value = (int)roundf((raw * (1 << integer)));
}

int 	Fixed::getRawBits( void ) const
{
	return (this->value);
}

void 	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->value / (1 << integer));
}

int		Fixed::toInt( void ) const
{
	return (this->value >> integer);
}

Fixed 	&Fixed::operator = ( const Fixed& fixed )
{
	this->value = fixed.getRawBits();
	return (*this);
}

// ========== comparison operators ==========

bool	Fixed::operator > ( const Fixed& fixed ) const
{
	if (this->value > fixed.value)
		return (1);
	else
		return (0);
}

bool	Fixed::operator < ( const Fixed& fixed ) const
{
	if (this->value < fixed.value)
		return (1);
	else
		return (0);
}

bool	Fixed::operator >= ( const Fixed& fixed ) const
{
	if (this->value >= fixed.value)
		return (1);
	else
		return (0);
}

bool	Fixed::operator <= ( const Fixed& fixed ) const
{
	if (this->value <= fixed.value)
		return (1);
	else
		return (0);
}

bool	Fixed::operator == ( const Fixed& fixed ) const
{
	if (this->value == fixed.value)
		return (1);
	else
		return (0);
}

bool	Fixed::operator != ( const Fixed& fixed ) const
{
	if (this->value != fixed.value)
		return (1);
	else
		return (0);
}

// ========== arithmetic operators ==========

Fixed	Fixed::operator + ( const Fixed& fixed ) const
{
	Fixed temp;
	temp.setRawBits(this->value + fixed.value);
	return (temp);
}

Fixed	Fixed::operator - ( const Fixed& fixed ) const
{
	Fixed temp;
	temp.setRawBits(this->value - fixed.value);
	return (temp);
}

Fixed	Fixed::operator * ( const Fixed& fixed ) const
{
	float first = (float)this->value / (1 << integer);
	float second = (fixed.value >> integer);
	Fixed temp = first * second;
	return (temp);
}

Fixed	Fixed::operator / ( const Fixed& fixed ) const
{
	float first = (float)this->value / (1 << integer);
	float second = (fixed.value >> integer);
	Fixed temp = first / second;
	return (temp);
}

// ========== increment/decrement ==========

Fixed	&Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	this->value--;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++*this;
	return (temp);
}

const Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--*this;
	return (temp);
}

Fixed	Fixed::max( Fixed& first, Fixed& second )
{
	if (first.value > second.value)
		return first.toFloat();
	else
		return second.toFloat();
}

Fixed	Fixed::max( const Fixed& first, const Fixed& second )
{
	if (first.value > second.value)
		return first.toFloat();
	else
		return second.toFloat();
}

Fixed	Fixed::min( Fixed& first, Fixed& second )
{
	if (first.value < second.value)
		return first.toFloat();
	else
		return second.toFloat();
}

Fixed	Fixed::min( const Fixed& first, const Fixed& second )
{
	if (first.value < second.value)
		return first.toFloat();
	else
		return second.toFloat();
}

// ===============   ===============


Fixed::~Fixed()
{
}

std::ostream& operator << (std::ostream& os, const Fixed& fixed)
{
	return os << fixed.toFloat();
}
