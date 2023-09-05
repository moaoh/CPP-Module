#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap( const std::string name );
	ScavTrap( const ScavTrap& scavTrap );
	~ScavTrap();

	ScavTrap	&operator = ( const ScavTrap& scavTrap );

	void		attack( const std::string& target );
	void 		guardGate();
};

#endif
