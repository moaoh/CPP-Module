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

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignment operator called" << "\n";
	setRawBits(fixed.value);
	return (*this);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << "\n";
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "getRawBits member function called" << "\n";
	value = raw;
	return ;
}
