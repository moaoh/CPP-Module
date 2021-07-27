#include "Zombie.hpp"

int	main(void)
{
	Zombie *sujo_zombie = newZombie("sujo");
	Zombie *seongele_zombie = newZombie("seongele");

	sujo_zombie->announce();
	seongele_zombie->announce();

	randomChump("jiychoi");
	randomChump("jaewpark");

	delete sujo_zombie;
	delete seongele_zombie;
	return (0);
}