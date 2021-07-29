#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string _type)
{
	type = _type;
}

Weapon::~Weapon()
{

}

// const : 함수에서 멤버변수의 값을 수정 불가
std::string	Weapon::getType(void) const
{
	return (type);
}

void		Weapon::setType(std::string _type)
{
	type = _type;
	return ;
}