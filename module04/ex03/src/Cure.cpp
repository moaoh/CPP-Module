#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure( const Cure& other )
{
	this->type = other.type;
}

Cure::~Cure() {}


Cure &Cure::operator = ( const Cure& other )
{
	this->type = other.type;
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}
