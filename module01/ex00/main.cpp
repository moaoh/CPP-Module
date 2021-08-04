#include "Zombie.hpp"

const std::string zombies[] = {
	"sujo",
	"seongele",
	"jiychoi",
	"jaewpark",
	"mjung",
};

int	main(void)
{
	Zombie stack_zombie = Zombie("stack");
	Zombie* heap_zombie = newZombie("heap");

	stack_zombie.announce();
	heap_zombie->announce();

	for (int i = 0; i < 42; i++)
		randomChump(zombies[rand() % 5]);

	delete heap_zombie;
	
	return (0);
}