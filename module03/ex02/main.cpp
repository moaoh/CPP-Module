#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int		main(void)
{
	ClapTrap *bmo = new ClapTrap("BMO");
	ScavTrap *finn = new ScavTrap("finn");
	FragTrap *iceKing = new FragTrap("Ice King");

	bmo->attack("Ice King");
	iceKing->takeDamage(5);
	iceKing->highFivesGuys();
	finn->guardGate();

	delete bmo;
	delete finn;
	delete iceKing;

	return (0);
}
