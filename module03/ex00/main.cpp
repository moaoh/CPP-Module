#include "ClapTrap.hpp"

int		main(void)
{
	ClapTrap bmo("BMO");
	ClapTrap iceKing("Ice King");

	bmo.attack("Ice King");
	iceKing.takeDamage(0);
	iceKing.attack("BMO");
	bmo.takeDamage(0);
	bmo.beRepaired(5);
	bmo.attack("Ice King");
	iceKing.takeDamage(0);
	iceKing.takeDamage(0);

	return (0);
}
