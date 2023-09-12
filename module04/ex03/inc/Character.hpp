#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	AMateria *slots[4];
	std::string	name;
public:
	Character();
	Character( const std::string name );
	Character( const Character& other );
	~Character();
	Character &operator = ( const Character& other );

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};


#endif
