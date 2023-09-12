#include "Character.hpp"

Character::Character()
{
}

Character::Character( const std::string name )
{

}

Character::Character( const Character& other )
{

}

Character::~Character()
{
}

Character &Character::operator = ( const Character& other )
{

}
std::string const & Character::getName() const
{
}

void  Character::equip(AMateria* m)
{
}

void  Character::unequip(int idx)
{
}

void  Character::use(int idx, ICharacter& target)
{
}

