#include "HumanB.hpp"

HumanB::HumanB() {}

HumanB::HumanB(std::string _name)
{
	name = _name;
}	

HumanB::~HumanB() {}

void	HumanB::attack()
{
	std::cout << name << " attacks with his " << weapon.getType() << "\n";
}

void	HumanB::setWeapon(Weapon& _weapon)
{
	weapon = _weapon;
}