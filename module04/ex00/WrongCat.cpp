#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << this->type << " Default constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& wrongCat )
{
	this->type = wrongCat.type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &WrongCat::operator = ( const WrongCat& wrongCat )
{
	this->type = wrongCat.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong~ miaoh Wrong~ miaoh!" << std::endl;
}