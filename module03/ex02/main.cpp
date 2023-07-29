#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int		main(void)
{
	ClapTrap bmo("BMO");
	FragTrap iceKing("Ice King");

	bmo.attack("Ice King");
	iceKing.takeDamage(5);
	iceKing.highFivesGuys();

	return (0);
}