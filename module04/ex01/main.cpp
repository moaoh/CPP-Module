#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
	Animal *animal[10];

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}
	for (int i = 0; i < 10; i++) {
		delete animal[i];
	}

// ========== deep copy ==========

	Cat	*operatorTest = new Cat();
	Cat	*operatorCopy = new Cat();

	*operatorTest = *operatorCopy;

	delete operatorTest;
	delete operatorCopy;

	// system("leaks Brain");
	return 0; 
}