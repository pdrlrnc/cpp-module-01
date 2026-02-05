#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
	public:
		void announce (void);
		Zombie(std::string name);
		~Zombie();
		Zombie();
		void setName(std::string name);
	private:
		std::string _name;
};
#endif
