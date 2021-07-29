#	ifndef WEAPON_HPP
#	define WEAPON_HPP

#	include <iostream>
#	include <string>

class Weapon
{
private:
	std::string	type;
	/* data */
public:
	Weapon();
	Weapon(std::string _type);
	~Weapon();
	std::string getType() const;
	void 		setType(std::string _type);
};

#	endif