#include "ClapTrap.hpp"

int		main(void)
{
	ClapTrap user("BMO");

	user.attack( "Ice King" );
	user.takeDamage( 5 );
	user.beRepaired( 10 );

	return (0);
}