#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << this->type << " Default constructor called" << std::endl;
}

Cat::Cat( const Cat& cat )
{
	this->type = cat.type;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator = ( const Cat& cat )
{
	this->type = cat.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "miaoh miaoh!" << std::endl;
}