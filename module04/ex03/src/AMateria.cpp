#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "none";
}

AMateria::AMateria( const AMateria& other )
{
	this->type = other.type;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator = ( const AMateria& other )
{
	this->type = other.type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}


void AMateria::use(ICharacter& target)
{
	if (target.getName() == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() <<  " *" << std::endl;
	else if (target.getName() == "cure")
		std::cout << "* heals " << target.getName() <<  "'s wounds *" << std::endl;
}
