#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;

	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap( const std::string name ) : ClapTrap( name )
{
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;

	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " Destructor called" << std::endl;
}

void 	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " highFive!!" << std::endl;
}