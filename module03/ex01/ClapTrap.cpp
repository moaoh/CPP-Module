#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "";
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;

	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( const std::string name )
{
	this->name = name;
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;

	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& clapTrap )
{
	this->name = clapTrap.name;
	this->hitPoint = clapTrap.hitPoint;
	this->energyPoint = clapTrap.energyPoint;
	this->attackDamage = clapTrap.attackDamage;

	std::cout << "ClapTrap " << name << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " Destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator = ( const ClapTrap& clapTrap )
{
	this->name = clapTrap.name;
	this->hitPoint = clapTrap.hitPoint;
	this->energyPoint = clapTrap.energyPoint;
	this->attackDamage = clapTrap.attackDamage;

	std::cout << "ClapTrap operator " << this->name << " = " << clapTrap.name << " called" << std::endl;
	return (*this);
}

// ClapTrap <name> attacks <target>, causing <damage> points of damage!
void	ClapTrap::attack( const std::string& target )
{
	if (!this->energyPoint || !this->hitPoint)
		std::cout << "ClapTrap " << this->name << " can't not attack.. ⚔︎";
	else
	{
		energyPoint--;
		std::cout << "ClapTrap " << this->name << " attacks " << target << "," << \
					" causing " << this->attackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage( unsigned int amount )
{	
	if (!this->hitPoint)
		std::cout << "ClapTrap " << this->name << " is dead.. 🪦" << std::endl;
	else
	{
		this->hitPoint -= amount;
		std::cout << this->name << " takeDamage 🦴 " << amount << ", hitPoint ❤️  : " << hitPoint << std::endl;
	}
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (!this->energyPoint || !this->hitPoint)
		std::cout << "ClapTrap " << this->name << " can't beRepaired.. ⚙" << std::endl;
	else
	{
		energyPoint--;
		this->hitPoint += amount;
		std::cout << this->name << " beRepaired... 🔧 " << amount << ", hitPoint ❤️  : " << hitPoint << std::endl;
	}
}