#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << "\n";
	this->name = "";
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap( const std::string name )
{
	std::cout << name << " constructor called" << "\n";
	this->name = name;
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap( const ClapTrap& clapTrap )
{
	std::cout << "Copy constructor called" << "\n";
	*this = clapTrap;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << "\n";
}

ClapTrap	&ClapTrap::operator = ( const ClapTrap& clapTrap )
{
	std::cout << "Copy assignment operator called" << "\n";
	this->name = clapTrap.name;
	this->hitPoint = clapTrap.hitPoint;
	this->energyPoint = clapTrap.energyPoint;
	this->attackDamage = clapTrap.attackDamage;
	return (*this);
}

// ClapTrap <name> attacks <target>, causing <damage> points of damage!
void	ClapTrap::attack( const std::string& target )
{
	if (energyPoint > 0 && hitPoint > 0)
	{
		energyPoint--;
		std::cout << "ClapTrap " << this->name << " attacks " << target << "," << \
					" causing " << this->attackDamage << " points of damage!" << "\n";
	}
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "takeDamage 🦴 " << "hitPoint : " << hitPoint << "\n";
	this->hitPoint -= amount;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (energyPoint > 0 && hitPoint > 0)
	{
		energyPoint--;
		this->hitPoint += amount;
		std::cout << "beRepaired... 🔧 " << "hitPoint : " << hitPoint << "\n";
	}
}