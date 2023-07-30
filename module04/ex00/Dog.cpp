#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << this->type << " Default constructor called" << std::endl;
}

Dog::Dog( const Dog& dog )
{
	this->type = dog.type;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator = ( const Dog& dog )
{
	this->type = dog.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof Woof!!" << std::endl;
}