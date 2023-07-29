#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string	name;
	int			hitPoint;
	int			energyPoint;
	int			attackDamage;
public:
	ClapTrap();
	ClapTrap( const std::string name );
	ClapTrap( const ClapTrap& clapTrap );
	virtual ~ClapTrap();

	ClapTrap	&operator = ( const ClapTrap& clapTrap );

	virtual void	attack( const std::string& target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );
};

#endif