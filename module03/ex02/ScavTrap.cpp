#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "none";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;

	std::cout << "[ScavTrap] Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( const std::string name ) : ClapTrap( name )
{
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;

	std::cout << "[ScavTrap] " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& scavTrap ) : ClapTrap( scavTrap )
{
	this->name = scavTrap.name;
	this->hitPoint = scavTrap.hitPoint;
	this->energyPoint = scavTrap.energyPoint;
	this->attackDamage = scavTrap.attackDamage;

	std::cout << "[ScavTrap] " << name << "Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] " << name << " Destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator = ( const ScavTrap& scavTrap )
{
	this->name = scavTrap.name;
	this->hitPoint = scavTrap.hitPoint;
	this->energyPoint = scavTrap.energyPoint;
	this->attackDamage = scavTrap.attackDamage;

	std::cout << "[ScavTrap] operator " << this->name << " = " << scavTrap.name << " called" << std::endl;
	return (*this);
}

// ScavTrap <name> attacks <target>, causing <damage> points of damage!
void	ScavTrap::attack( const std::string& target )
{
	if (this->energyPoint <= 0)
		std::cout << "[ScavTrap] " << this->name << "doesn't have energyPoint.. ⚔︎" << std::endl;
	else if (this->hitPoint <= 0)
		std::cout << "[ScavTrap] " << this->name << " is dead.. " << std::endl;
	else
	{
		energyPoint--;
		std::cout << "[ScavTrap] " << this->name << " attacks " << target << "," << \
					" causing " << this->attackDamage << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] " << this->name << " Gate keeper mode." << std::endl;
}
