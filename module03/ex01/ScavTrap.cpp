#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;

	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( const std::string name ) : ClapTrap( name )
{
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;

	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " Destructor called" << std::endl;
}

// ScavTrap <name> attacks <target>, causing <damage> points of damage!
void	ScavTrap::attack( const std::string& target )
{
	if (!this->energyPoint || !this->hitPoint)
		std::cout << "ScavTrap " << this->name << " can't not attack.. ⚔︎";
	else
	{
		energyPoint--;
		std::cout << "ScavTrap " << this->name << " attacks " << target << "," << \
					" causing " << this->attackDamage << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " Gate keeper mode." << std::endl;
}