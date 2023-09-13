#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *dogBrain;
public:
	Dog();
	Dog( const Dog& dog );
	~Dog();

	Dog &operator = ( const Dog& dog );

	virtual void	makeSound() const;
};

#endif
