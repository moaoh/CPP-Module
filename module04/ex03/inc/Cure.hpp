#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
public:
	Cure();
	virtual ~Cure();
	Cure( const Cure& other );
	Cure &operator = ( const Cure& other );

	virtual AMateria* clone() const;
};

#endif
