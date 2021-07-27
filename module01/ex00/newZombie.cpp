#include "Zombie.hpp"

// write a function that will create a Zombie, 
// name it, and return it to be used somewhere else in your code.

Zombie* newZombie( std::string name )
{
	Zombie *zomble = new Zombie(name);

	return (zomble);
}