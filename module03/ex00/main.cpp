#include "ClapTrap.hpp"

int		main(void)
{
	ClapTrap bmo("BMO");
	ClapTrap iceKing("Ice King");

	bmo.attack("Ice King");
	iceKing.takeDamage(5);
	iceKing.attack("BMO");
	bmo.takeDamage(5);
	bmo.beRepaired(5);
	bmo.attack("Ice King");
	iceKing.takeDamage(5);
	iceKing.takeDamage(5);

	return (0);
}
