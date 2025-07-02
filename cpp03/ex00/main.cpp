#include "ClapTrap.hpp"
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

	printTitle("ATTACK");
	claptrap.attack("Darth Vader");
	claptrapCopy.attack("Obi-Wan Kenobi");
	anotherClaptrap.attack("Emperor Palpatine");

	printTitle("TAKE DAMAGE");
	claptrap.takeDamage(5);
	claptrapCopy.takeDamage(3);
	anotherClaptrap.takeDamage(10);

	printTitle("BE REPAIRED");
	claptrap.beRepaired(2);
	claptrapCopy.beRepaired(5);
	anotherClaptrap.beRepaired(1);

	printTitle("FINAL STATE");
	std::cout << claptrap << std::endl;
	std::cout << claptrapCopy << std::endl;
	std::cout << anotherClaptrap << std::endl;

	return 0;
}