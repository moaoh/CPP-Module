#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "?";
	std::cout << this->type << " make Amateria" << std::endl;
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
	this->type = type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}
