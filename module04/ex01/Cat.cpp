#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << this->type << " Default constructor called" << std::endl;
	this->catBrain = new Brain();
}

Cat::Cat( const Cat& cat ) : Animal(cat)
{
	this->type = cat.type;
	this->catBrain = new Brain();
	*this->catBrain = *cat.catBrain;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->catBrain;
}

Cat &Cat::operator = ( const Cat& cat )
{
	if (this != &cat)
	{
		this->type = cat.type;
		delete this->catBrain;
		this->catBrain = new Brain();
		*this->catBrain = *cat.catBrain;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "miaoh miaoh!" << std::endl;
}
