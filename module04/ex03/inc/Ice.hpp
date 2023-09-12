#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	/* data */
public:
	Ice(/* args */);
	Ice( const Ice& other );
	virtual ~Ice();
	Ice &operator = ( const Ice& other );

	virtual AMateria* clone() const;
};

#endif

