#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << this->type << " Default constructor called" << std::endl;
	this->dogBrain = new Brain();
}

Dog::Dog( const Dog& dog )
{
	this->type = dog.type;
	this->dogBrain = new Brain();
	*this->dogBrain = *dog.dogBrain;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->dogBrain;
}

Dog &Dog::operator = ( const Dog& dog )
{
	this->type = dog.type;
	*this->dogBrain = *dog.dogBrain;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof Woof!!" << std::endl;
}