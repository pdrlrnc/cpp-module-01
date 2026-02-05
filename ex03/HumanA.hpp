#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
	public:
		void attack(void);
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
	private:
		std::string _name;
		Weapon& _weapon;

};

#endif
