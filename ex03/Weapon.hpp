#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon 
{
	private:
		std::string _type;
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		std::string getType(void) const;
		void setType(const std::string& new_type);
	
};

#endif
