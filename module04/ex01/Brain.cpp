#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "make Brain" << std::endl;
}

Brain::Brain( const Brain& brain )
{
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = brain.ideas[i];
	}
}

Brain::~Brain()
{
	std::cout << "breaks Brain" << std::endl;
}

Brain &Brain::operator = ( const Brain& brain )
{
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = brain.ideas[i];
	}
	return (*this);
}
