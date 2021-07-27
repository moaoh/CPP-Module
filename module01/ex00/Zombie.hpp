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
		Zombie(std::string _name);
		~Zombie(void);
		void announce(void);
};

// ------------------------------------

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#	endif