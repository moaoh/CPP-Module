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

Fixed::Fixed( const int raw )
{
	std::cout << "Int constructor called" << "\n";
	this->value = (raw << integer);
}

Fixed::Fixed( const float raw )
{
	std::cout << "Float constructor called" << "\n";
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
	std::cout << "Copy assignment operator called" << "\n";
	this->value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << "\n";
}

std::ostream& operator << (std::ostream& os, const Fixed& fixed)
{
	return os << fixed.toFloat();
}