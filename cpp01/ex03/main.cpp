#include "Weapon.hpp"
#include <string>
#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
// FROM SUBJECT	
	{
		std::cout << "FROM SUBJECT" << std::endl;
		std::cout << "HUMAN A" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", &club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		std::cout << std::endl;
	}
	{
		std::cout << "HUMAN B" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		std::cout << std::endl;
	}
//MY TEST
	{
		std::cout << "MY TEST FOR HUMAN B" << std::endl;
		Weapon club = Weapon("AXE");
		HumanB dru("Drucilla");
		dru.attack();
		dru.setWeapon(club);
		dru.attack();
		club.setType("SWORD");
		dru.attack();
	}


	return 0;
}