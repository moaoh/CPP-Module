#include "Serializer.hpp"

int main(int ac, char *av[])
{
	Data original;
	Data *ShallowCopy;
	uintptr_t ptr;

	try {
		if (ac != 2) {
			throw std::invalid_argument("Invalid argument");
		}
		original.name = av[1];
		std::cout << "original : " << original.name << std::endl;

		ptr = Serializer::serialize(&original);
		std::cout << "ptr : " << ptr << std::endl;

		ShallowCopy = Serializer::deserialize(ptr);
		std::cout << "ShallowCopy : " << ShallowCopy->name << std::endl;

		ShallowCopy->name = "change name";
		std::cout << "original : " << original.name << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "error :" << e.what() << '\n';
	}

	return (0);
}
