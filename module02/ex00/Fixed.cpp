#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << "\n";
	value = 0;
}

Fixed::Fixed( const Fixed& fixed )
{
	std::cout << "Copy constructor called" << "\n";
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << "\n";
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << "\n";
	return (this->value);
}
