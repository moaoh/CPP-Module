#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "none";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;

	std::cout << "[FragTrap] Default constructor called" << std::endl;
}

FragTrap::FragTrap( const std::string name ) : ClapTrap( name )
{
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;

	std::cout << "[FragTrap] " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap& fragTrap ) : ClapTrap( fragTrap )
{
	this->name = fragTrap.name;
	this->hitPoint = fragTrap.hitPoint;
	this->energyPoint = fragTrap.energyPoint;
	this->attackDamage = fragTrap.attackDamage;

	std::cout << "[FragTrap] " << name << "Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] " << name << " Destructor called" << std::endl;
}

FragTrap	&FragTrap::operator = ( const FragTrap& fragTrap )
{
	this->name = fragTrap.name;
	this->hitPoint = fragTrap.hitPoint;
	this->energyPoint = fragTrap.energyPoint;
	this->attackDamage = fragTrap.attackDamage;

	std::cout << "[FragTrap] operator " << this->name << " = " << fragTrap.name << " called" << std::endl;
	return (*this);
}

void 	FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap] " << name << " highFive!!" << std::endl;
}
