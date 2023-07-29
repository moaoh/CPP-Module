#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	ClapTrap bmo("BMO");
	ScavTrap iceKing("Ice King");

	bmo.attack("Ice King");
	iceKing.takeDamage(5);
	iceKing.guardGate();
	iceKing.attack("BMO");
	bmo.takeDamage(20);

	return (0);
}