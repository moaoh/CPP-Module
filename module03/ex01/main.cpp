#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	ClapTrap *bmo = new ClapTrap("BMO");
	ScavTrap *iceKing = new ScavTrap("Ice King");

	bmo->attack("Ice King");
	iceKing->takeDamage(5);
	iceKing->guardGate();
	iceKing->attack("BMO");
	bmo->takeDamage(20);
	bmo->takeDamage(1);

	delete bmo;
	delete iceKing;

	return (0);
}
