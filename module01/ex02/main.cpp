#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* PTR = &str;
	std::string& REF = str;

	std::cout << *PTR << "\n";
	std::cout << REF << "\n";

	return (0);
}