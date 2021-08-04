#include "Zombie.hpp"

Zombie::Zombie()
{
	Name = "None";
}

Zombie::Zombie(std::string _name)
{
	Name = _name;
}

Zombie::~Zombie(void)
{
	std::cout << "\e[91m" + Name + "\e[0m" << "\e[31m died... 🪦\e[0m" << "\n";
}

void Zombie::announce(void)
{
	std::cout << "🧟 " << "\e[1m" + Name + "\e[0m" << " \e[32mBraiiiiiiinnnzzzZ...\033[0m" << "\n";
}

void Zombie::cin_name(std::string name)
{
	Name = name;
}
