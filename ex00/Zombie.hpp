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
	private:
		std::string _name;
};
#endif
