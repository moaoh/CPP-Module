#include "ClapTrap.hpp"

int		main(void)
{
	ClapTrap bmo("BMO");
	ClapTrap iceKing("Ice King");

	bmo.attack("Ice King");
	iceKing.takeDamage(3);
	iceKing.attack("BMO");
	bmo.takeDamage(6);
	bmo.beRepaired(5);
	bmo.attack("Ice King");
	iceKing.takeDamage(7);
	iceKing.takeDamage(1);

	return (0);
}