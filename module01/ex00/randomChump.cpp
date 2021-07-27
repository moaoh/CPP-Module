#include "Zombie.hpp"

// You will also have to write another function that will create a Zombie,
// and make it announce itself.

void randomChump( std::string name )
{
	Zombie zombie(name);
	zombie.announce();
}