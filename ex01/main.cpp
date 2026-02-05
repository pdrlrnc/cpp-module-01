#include "Zombie.hpp"
#include <iostream>
#include <ostream>


/* prototypes */
Zombie *zombieHorde(int N, std::string name);

int main ()
{
	std::cout 
		<< "A random horde of 20 zombies is approaching!!!!!1!!1!" << std::endl 
		<< "Weirdly, they all have the same name (Horace)" << std::endl;
	Zombie *horde = zombieHorde(20, "Horace");
	std::cout
		<< "OMG! They are about to announce themselves!!!" << std::endl;
	for (int i = 0; i < 20; i++)
	{
		std::cout
			<< "[" << i + 1 << "] ";
		(horde[i]).announce();
	}
	std::cout
		<< "Okay, this is getting ridiculous, I will shoo them away for you..." << std::endl;
	delete[] horde;
}
