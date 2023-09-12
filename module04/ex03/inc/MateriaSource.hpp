#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	/* data */
public:
	MateriaSource();
	MateriaSource( const MateriaSource& other );
	~MateriaSource();
	MateriaSource &operator = ( const MateriaSource& other );

	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const & type);
};

#endif
