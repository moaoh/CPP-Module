#include "phone_book.hpp"

void	phone_book::ADD(void)
{
	std::string	temp;

	std::cout << "first_name : ";
	getline(std::cin, temp);
	first_name = temp;
	std::cout << "last_name : ";
	getline(std::cin, temp);
	last_name = temp;
	std::cout << "nickname : ";
	getline(std::cin, temp);
	nickname = temp;
	std::cout << "phone_number : ";
	getline(std::cin, temp);
	phone_number = temp;
	std::cout << "darkest_secret : ";
	getline(std::cin, temp);
	darkest_secret = temp;
}

void	phone_book::blank_space(int num)
{
	int count = 10 - num;

	for(int i = 0; i < count; i++)
		std::cout << " ";	
}

void	phone_book::cout_search(std::string& str)
{
	if (str.length() < 10)
		std::cout << str << "|";
	else
	{
		for (int i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout << "." << "|";
	}
}

// index, first name, last name and nickname
void	phone_book::SEARCH(void)
{
	blank_space(first_name.length());
	cout_search(first_name);
	blank_space(last_name.length());
	cout_search(last_name);
	blank_space(nickname.length());
	cout_search(nickname);
	std::cout << "\n";
}

void	phone_book::cout_contact(void)
{
	std::cout << "first_name : ";
	std::cout << first_name << "\n";
	std::cout << "last_name : ";
	std::cout << last_name << "\n";
	std::cout << "nickname : ";
	std::cout << nickname << "\n";
	std::cout << "phone_number : ";
	std::cout << phone_number << "\n";
	std::cout << "darkest_secret : ";
	std::cout << darkest_secret << "\n";
}