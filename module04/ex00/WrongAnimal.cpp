#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << this->type << " Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& wrongAnimal )
{
	this->type = wrongAnimal.type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator = ( const WrongAnimal& wrongAnimal )
{
	this->type = wrongAnimal.type;
	return (*this);
}

std::string			WrongAnimal::getType() const
{
	return (this->type);
}

void			WrongAnimal::makeSound() const
{
	std::cout << "Wrong Wrong Ani! Ani! mal mal!!" << std::endl;
}