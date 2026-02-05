#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type)
	:_type(type){}

Weapon::~Weapon(){}

std::string Weapon::getType(void) const
{
	return (_type);
}

void Weapon::setType(const std::string& new_type)
{
	_type = new_type;
}
