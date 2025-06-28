#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


#include <iostream>


class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string _name;

public:
	// Constructors and Destructor	
	DiamondTrap(); // Default constructor
	DiamondTrap(const DiamondTrap &other); // Parameterized constructor
	DiamondTrap(const std::string &name); // Parameterized constructor
	~DiamondTrap(); // Destructor

	DiamondTrap &operator=(const DiamondTrap &other); // Copy assignment operator

	// Member functions
	// Inherits attack method from ScavTrap and FragTrap
	// void takeDamage(unsigned int amount); // Method to take damage (inherited from ClapTrap)
	// void beRepaired(unsigned int amount); // Method to repair itself (inherited from ClapTrap)

	void attack(const std::string &target); // Method to attack a target
	// void takeDamage(unsigned int amount); // Method to take damage
	// void beRepaired(unsigned int amount); // Method to repair itself


	void whoAmI(void); // Method to print the name of the DiamondTrap
	// Getters and Setters
	const std::string& getName() const; // Getter for name
	unsigned int getHitPoints() const; // Getter for hit points
	unsigned int getEnergyPoints() const; // Getter for energy points
	unsigned int getAttackDamage() const; // Getter for attack damage
	void setName(const std::string &name); // Setter for name
};

// Overloaded output operator for Diamond
std::ostream &operator<<(std::ostream &os, const DiamondTrap &DiamondTrap);

#endif // DIAMONDTRAP_HPP