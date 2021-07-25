#include <iostream>

int error_msg(void)
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
	return (1);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (error_msg());
	for (int i = 1; argv[i]; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			std::cout << (char)toupper(argv[i][j]);
	}
	std::cout << "\n";
	
	return (0);
}
