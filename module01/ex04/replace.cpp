#include "Replace.hpp"

Replace::Replace()
{
	std::string	temp;

	std::cout << "\e[1m" << "📜 FILENAME : " << "\e[0m";
	std::getline(std::cin, FILENAME);
	if (std::cin.eof())
		exit(1);
	std::cout << "\e[1m" << "old value : " << "\e[0m";
	std::getline(std::cin, old_value);
	if (std::cin.eof())
		exit(1);
	std::cout << "\e[1m" << "new value : " << "\e[0m";
	std::getline(std::cin, new_value);
	if (std::cin.eof())
		exit(1);
}

Replace::~Replace()
{

}

std::string	Replace::cout_value(std::string type)
{
	if (type == "FILENAME")
		return (FILENAME);
	else if (type == "old_value")
		return (old_value);
	else if (type == "new_value")
		return (new_value);
	else
		return (NULL);
}

int		Replace::value_validation()
{
	if (FILENAME.empty())
	{
		std::cout << "Error: Invalid FILENAME" << "\n";
		//std::cout << "FILENAME : " << FILENAME << "\n";
		return (1);
	}
	if (old_value.empty())
	{
		std::cout << "Error: Invalid old_value " << "\n";
		//std::cout << "replace_value : " << old_value << "\n";
		return (1);
	}
	if (new_value.empty())
	{
		std::cout << "Error: Invalid new_value " << "\n";
		//std::cout << "changed_value : " << new_value << "\n";
		return (1);
	}
	return (0);
}