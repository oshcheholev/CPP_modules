#include "Harl.hpp"
#include <iostream>
#include <string>
#include <cstring>

#define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for it!"
#define WARNING_MSG "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
#define ERROR_MSG "This is unacceptable! I want to speak to the manager now."
#define DEBUG_STR "[ DEBUG ]"
#define INFO_STR "[ INFO ]"
#define WARNING_STR "[ WARNING ]"
#define ERROR_STR "[ ERROR ]"
#define NO_COMPLAIN "[ Probably complaining about insignificant problems ]"


Harl::Harl()
{
}
Harl::~Harl()
{
}
void Harl::debug(void)
{
	std::cout << DEBUG_STR << std::endl;
	std::cout << DEBUG_MSG << std::endl;
}
void Harl::info(void)
{
	std::cout << INFO_STR << std::endl;
	std::cout << INFO_MSG << std::endl;
}
void Harl::warning(void)
{
	std::cout << WARNING_STR << std::endl;
	std::cout << WARNING_MSG << std::endl;
}
void Harl::error(void)
{
	std::cout << ERROR_STR << std::endl;
	std::cout << ERROR_MSG << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*f[4])(void) = 
	{
		&Harl::debug, 
		&Harl::info, 
		&Harl::warning, 
		&Harl::error
	};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4 && level != levels[i])
		i++;
	switch (i)
	{
		case DEBUG:
			(this->*f[DEBUG])();
			std::cout << std::endl;
			(this->*f[INFO])();
			std::cout << std::endl;
			(this->*f[WARNING])();
			std::cout << std::endl;
			(this->*f[ERROR])();
			break;
		case INFO:
			(this->*f[INFO])();
			std::cout << std::endl;
			(this->*f[WARNING])();
			std::cout << std::endl;
			(this->*f[ERROR])();
			std::cout << std::endl;
			break;
		case WARNING:
			(this->*f[WARNING])();
			std::cout << std::endl;
			(this->*f[ERROR])();
			std::cout << std::endl;
			break;
		case ERROR:
			(this->*f[ERROR])();
			std::cout << std::endl;
			break;
		default:
			std::cout << NO_COMPLAIN << std::endl;
			break;
	}
}