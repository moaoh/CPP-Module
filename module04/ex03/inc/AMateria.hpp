#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	AMateria( const AMateria& other );
	AMateria(std::string const & type);

	std::string const & getType() const; //Returns the materia type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

	AMateria &operator = ( const AMateria& other );
};

#endif
