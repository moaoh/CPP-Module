#include "Zombie.hpp"

int	main(void)
{
	std::string name;
	int			N;

	std::cout << "zombie name : ";
	std::cin >> name;
	std::cout << "zombie N : ";
	std::cin >> N;

	Zombie* zombies = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;

	return (0);
}