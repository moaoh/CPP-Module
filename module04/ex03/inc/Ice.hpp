#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	/* data */
public:
	Ice(/* args */);
	~Ice();

	virtual AMateria* clone() const;
};

#endif
