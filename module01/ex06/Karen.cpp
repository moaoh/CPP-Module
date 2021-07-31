#include "Karen.hpp"

Karen::Karen()
{

}

Karen::~Karen()
{

}

void	Karen::debug()
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << "\n";
}

void	Karen::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money." << "\n" << \
				"You don’t put enough! If you did I would not have to ask for it!" << "\n";
}

void	Karen::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free." << "\n" << \
				"I’ve been coming here for years and you just started working here last month." << "\n";
}

void	Karen::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << "\n";
}

void	Karen::karenFilter( std::string level )
{
	std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};

	void (Karen::*actions[4]) () = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error,
	};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			for (int j = i; j < 4; j++)
			{
				std::cout << "[ " + levels[j] + " ]" << "\n";
				(this->*actions[j]) ();
				std::cout << "\n";
			}
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << "\n";
}