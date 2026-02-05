#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
	public:
		void attack(void);
		Weapon* _weapon;
		std::string _name;
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon& weapon);

};

#endif
