#ifndef SKAVTRAP_HPP
#define SKAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"


class ScavTrap : virtual public ClapTrap {
	// Inherits from ClapTrap to use its members and methods
	// This allows ScavTrap to have the same properties as ClapTrap
	// while also adding its own unique features.
protected:	// Protected members to allow access in derived classes
	// These members can be accessed by derived
	// std::string _name;
	// unsigned int _hitPoints;
	// unsigned int _energyPoints;
	// unsigned int _attackDamage;
public:
	// Constructors and Destructor	
	ScavTrap(); // Default constructor
	ScavTrap(const ScavTrap &other); // Parameterized constructor
	ScavTrap(const std::string &name); // Parameterized constructor
	~ScavTrap(); // Destructor

	ScavTrap &operator=(const ScavTrap &other); // Copy assignment operator

	void attack(const std::string &target); // Method to attack a target
	void guardGate(); // Method to enter guard mode

};
std::ostream &operator<<(std::ostream &os, const ScavTrap &scavTrap);

#endif // CLAPTRAP_HPP
