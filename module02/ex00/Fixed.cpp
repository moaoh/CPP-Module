#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << "\n";
	this->value = 0;
}

Fixed::Fixed( const Fixed& fixed )
{
	std::cout << "Copy constructor called" << "\n";
	*this = fixed;
}

Fixed &Fixed::operator = ( const Fixed& fixed )
{
	std::cout << "Copy assignment operator called" << "\n";
	this->value = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << "\n";
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << "\n";
	this->value = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << "\n";
}
