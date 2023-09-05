#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int		main(void)
{
	ClapTrap *bmo = new ClapTrap("BMO");
	FragTrap *iceKing = new FragTrap("Ice King");

	bmo->attack("Ice King");
	iceKing->takeDamage(5);
	iceKing->highFivesGuys();

	delete bmo;
	delete iceKing;

	return (0);
}
