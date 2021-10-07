#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed( const Fixed& fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->integer;
	// this->value = value;
}

Fixed::Fixed( const float value )
{
	std::cout << "Float constructor called" << std::endl;
	this->value = (int)roundf(value * (1 << this->integer));
	// std::cout << "float : " << this->value << std::endl;
	// this->value = value;
}

Fixed &Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Assignment operator called" << std::endl;
	this->value = fixed.value;
	return (*this);
}

std::ostream& operator << (std::ostream &os, const Fixed &value)
{
	os << value.toFloat();
	return (os);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->value / (1 << this->integer));
	// return (this->value);
}

int Fixed::toInt( void ) const
{
	return (this->value >> this->integer);
	// return (this->value);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}