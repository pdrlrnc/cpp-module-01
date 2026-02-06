#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
		std::cout
			<< "Required params: [DEBUG LEVEL]" << std::endl;
	else
		harl.complain(argv[1]);
	return (0);
}
