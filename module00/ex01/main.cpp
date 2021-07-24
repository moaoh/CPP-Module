#include "phone_book.hpp"

void				explanation(void)
{
	std::cout << "you should accept the ADD command, the SEARCH command or the EXIT command." << "\n";
	std::cout << "EXIT : program quits." << "\n";
	std::cout << "ADD : new contact’s information." << "\n";
	std::cout << "SEARCH : SEARCH phone_book." << "\n";
}

int					main(void)
{
	std::string		input;
	phone_book		phone_book[8];
	int				count = 0;

	explanation();
	while (true)
	{
		std::cout << "📖 phone_book : ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			phone_book[count].ADD();
			std::cout << "It's been saved in number " << count + 1 << "\n";
			count++;
		}
		else if (input == "SEARCH")
		{
			for (int i = 0; i < 8; i++)
				phone_book[i].SEARCH();
		}
		else
		{
			std::cout << "Invalid input value. (EXIT, ADD, SEARCH)" << "\n";
		}
		if (count >= 8)
			count = 0;
	}
	
	std::cout << "good bye :D" << "\n";
	return (0);
}