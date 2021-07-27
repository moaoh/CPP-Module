#	ifndef ZOMBIE_HPP
#	define ZOMBIE_HPP

// icnlude ----------------------------

#	include <iostream>
#	include <string>

// class ------------------------------

class Zombie
{
	private:
		std::string	Name;

	public:
		Zombie();
		Zombie(std::string _name);
		~Zombie(void);
		void announce(void);
		void cin_name(std::string name);
};

// ------------------------------------

Zombie* zombieHorde( int N, std::string name );

#	endif