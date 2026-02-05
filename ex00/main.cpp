#include "Zombie.hpp"
#include <iostream>


/* prototypes */
Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main ()
{
	std::cout 
		<< "This zombie is gonna be on the stack (Stan)" << std::endl;
	randomChump("Stan");

	std::cout
		<< "This zombie is gonna be on the heap (Hephaestus)" << std::endl;

	Zombie *hep;
	try 
	{
		hep = newZombie("Hephaestus");
	} catch (const std::bad_alloc& e)
	{
		std::cout 
			<< "Memory allocation failed. Exiting..." << std::endl;
		return (1);
	}
	
	std::cout
		<< "Get ready for Hephaestus' announcement!!" << std::endl;
	hep->announce();
	std::cout
		<< "That was exciting! Say your goodbies to Hephaestus." << std::endl;
	delete hep;
	return (0);
}
