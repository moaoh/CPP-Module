#include "Character.hpp"

// slots을 빈값으로 초기화를 진행해줘야한다.
Character::Character()
{
	this->name = "none";
	for (int i = 0; i < 4; i++) {
		this->slots[i] = NULL;
	}
}

Character::Character( const std::string name )
{
	this->name = name;
	for (int i = 0; i < 4; i++) {
		this->slots[i] = NULL;
	}
}

Character::Character( const Character& other )
{
	this->name = other.name;
	for (int i = 0; i < 4; i++) {
		this->slots[i] = other.slots[i];
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++) {
		delete this->slots[i];
	}
}

Character &Character::operator = ( const Character& other )
{
	this->name = other.name;
	for (int i = 0; i < 4; i++) {
		this->slots[i] = other.slots[i];
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->name);
}

void  Character::equip(AMateria* m)
{
	if (!m) return;
	for (int i = 0; i < 4; i++) {
		if (!this->slots[i]) {
			this->slots[i] = m;
			return;
		}
	}
}

void  Character::unequip(int idx)
{
	if (0 <= idx && idx < 4) {
		this->slots[idx] = NULL;
	}
}

// idx에 해당하는 스킬을 사용
void  Character::use(int idx, ICharacter& target)
{
	if (this->slots[idx]) {
		if (this->slots[idx]->getType() == "ice")
			std::cout << "* shoots an ice bolt at " << target.getName() <<  " *" << std::endl;
		else if (this->slots[idx]->getType() == "cure")
			std::cout << "* heals " << target.getName() <<  "'s wounds *" << std::endl;
	}
}

