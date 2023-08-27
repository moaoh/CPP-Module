#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << this->type << " Default constructor called" << std::endl;
}

Animal::Animal( const Animal& animal )
{
	this->type = animal.type;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal &Animal::operator = ( const Animal& animal )
{
	this->type = animal.type;
	return (*this);
}

std::string			Animal::getType() const
{
	return (this->type);
}