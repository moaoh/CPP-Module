#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure( const Cure& other ) : AMateria(other) {}

Cure::~Cure() {}

Cure &Cure::operator = ( const Cure& other )
{
	this->AMateria::operator=(other);
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}
