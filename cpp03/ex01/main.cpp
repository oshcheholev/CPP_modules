#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

void printTitle(const std::string& title) {
	std::cout << "\n" << BLUE << "--- " << title << " ---" << RESET << std::endl;
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;
}

int main() {
	
	printTitle("CLAPTRAP TEST");
	ClapTrap claptrap("R2D2");
	ClapTrap claptrapCopy(claptrap);
	ClapTrap anotherClaptrap = claptrapCopy;
	claptrapCopy.setName("C3PO");
	claptrap.attack("Darth Vader");
	claptrapCopy.attack("Obi-Wan Kenobi");
	anotherClaptrap.attack("Emperor Palpatine");
	claptrap.takeDamage(5);
	claptrapCopy.takeDamage(3);
	anotherClaptrap.takeDamage(10);
	claptrap.beRepaired(2);
	claptrapCopy.beRepaired(5);
	anotherClaptrap.beRepaired(1);
	std::cout << claptrap << std::endl;
	std::cout << claptrapCopy << std::endl;
	std::cout << anotherClaptrap << std::endl;

	printTitle("SCAVTRAP TEST");
	ScavTrap scavtrap("Luke Skywalker");
	ScavTrap scavtrapCopy(scavtrap);
	ScavTrap anotherScavtrap = scavtrapCopy;
	scavtrapCopy.setName("Han Solo");
	scavtrap.attack("Darth Vader");
	scavtrapCopy.attack("Obi-Wan Kenobi");
	anotherScavtrap.attack("Emperor Palpatine");
	scavtrap.takeDamage(5);
	scavtrapCopy.takeDamage(3);
	anotherScavtrap.takeDamage(10);
	scavtrap.beRepaired(2);
	scavtrapCopy.beRepaired(5);
	anotherScavtrap.beRepaired(1);

	printTitle("GUARD MODE TEST");
	scavtrap.guardGate();
	scavtrapCopy.guardGate();
	anotherScavtrap.guardGate();
	printTitle("THAT'S ALL FOLKS!");
	return 0;
}