#include "Harl.hpp"
#include <iostream>

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug(void)
{
	std::cout
		<< "[DEBUG]" << std::endl
		<< "I love having extra bacon for my 7XL-double-cheese"
		<< "-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void Harl::info(void)
{
	std::cout
		<< "[INFO]" << std::endl
		<< "I cannot believe adding extra bacon costs more money"
		<< ". You didn’t put enough bacon in my burger! If you di"
		<< "d, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout
		<< "[WARNING]" << std::endl
		<< "I think I deserve to have some extra bacon for free. I"
		<< "’ve been coming for years, whereas you started working h"
		<< "ere just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout
		<< "[ERROR]" << std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void Harl::_default(void)
{
	std::cout
		<< "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	
	void (Harl::*function[5])() = 
	{

		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
		&Harl::_default
	};

	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
			break;

	}
	switch (i)
	{
		case 0:
			(this->*function[0])();
			//fallthrough
		case 1:
			if (i != 1)
				std::cout << std::endl;
			(this->*function[1])();
			//fallthrough
		case 2:
			if (i != 2)
				std::cout << std::endl;
			(this->*function[2])();
			//fallthrough
		case 3:
			if (i != 3)
				std::cout << std::endl;
			(this->*function[3])();
			std::cout << std::endl;
			break;
		default:
			(this->*function[4])();
			break;
	}
}
