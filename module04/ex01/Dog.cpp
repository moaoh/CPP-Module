#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << this->type << " Default constructor called" << std::endl;
	this->dogBrain = new Brain();
}

Dog::Dog( const Dog& dog ) : Animal(dog)
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
	if (this != &dog)
	{
		this->type = dog.type;
		delete this->dogBrain;
		this->dogBrain = new Brain();
		*this->dogBrain = *dog.dogBrain;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof Woof!!" << std::endl;
}
