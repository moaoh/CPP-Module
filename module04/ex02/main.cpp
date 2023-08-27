#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
	Animal *cat = new Cat();
	Animal *dog = new Dog();

	cat->makeSound();
	dog->makeSound();

	delete cat;
	delete dog;

	return 0; 
}