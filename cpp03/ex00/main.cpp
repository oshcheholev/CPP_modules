#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap1("Clappy");
	ClapTrap claptrap2("Clapster");

	claptrap1.attack("target1");
	claptrap2.attack("target2");

	claptrap1.takeDamage(3);
	claptrap2.takeDamage(5);

	claptrap1.beRepaired(2);
	claptrap2.beRepaired(4);

	ClapTrap claptrap3 = claptrap1; // Copy constructor
	claptrap3.attack("target3");

	ClapTrap claptrap4;
	claptrap4 = claptrap2; // Assignment operator
	claptrap4.attack("target4");

	return 0;
}