#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	
	std::cout << "===Constructors===" << std::endl;
	DiamondTrap diamond1("Luke Skywalker");
//	diamond1.attack("Dart Wader");
	DiamondTrap diamond2("Leia Organa");
//	diamond2.attack("Emperor Palpatine");
	DiamondTrap diamond3 = diamond1; // Using copy constructor
	diamond3.setName("Han Solo"); // Set a different name for the copy
	std::cout << std::endl;
	std::cout << "===DiamondTrap Instances===" << std::endl;
	std::cout << diamond1 << std::endl;
	std::cout << diamond2 << std::endl;
	std::cout << diamond3 << std::endl;
	std::cout << std::endl;
	std::cout << "===Attacks===" << std::endl;
	diamond3.attack("Dart Wader");
	diamond2.attack("Emperor Palpatine");
	diamond1.attack("Master Yoda");

	std::cout << std::endl;
	std::cout << "===Take Damage and Repair===" << std::endl;
	diamond1.takeDamage(5);
	diamond2.takeDamage(3);
	diamond1.beRepaired(2);
	diamond2.beRepaired(4);
	std::cout << std::endl;
	std::cout << "===Who Am I?===" << std::endl;
	diamond1.whoAmI();
	diamond2.whoAmI();
	diamond3.whoAmI();
	std::cout << std::endl;

	std::cout << "===High Fives Guys===" << std::endl;
	diamond1.highFivesGuys();
	diamond2.highFivesGuys();
	diamond3.highFivesGuys();

	std::cout << std::endl;
	std::cout << "===Guard Gate===" << std::endl;
	diamond1.guardGate();
	diamond2.guardGate();
	diamond3.guardGate();
	std::cout << std::endl;
	std::cout << "===That's all folks!===" << std::endl;
	std::cout << std::endl;
	// Clean up
	// No explicit cleanup needed as we are using automatic storage duration (stack allocation)


	return 0;
}