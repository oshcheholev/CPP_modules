#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

// ANSI color codes for terminal output
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define MAGENTA "\033[35m"

class ClapTrap {
protected:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

public:
	// Constructors and Destructor
	ClapTrap(); // Default constructor
	ClapTrap(const std::string& name); // Parameterized constructor
	ClapTrap(const ClapTrap& other); // Copy constructor
	~ClapTrap(); // Destructor
	ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator

	// Member functions
	void attack(const std::string& target); // Method to attack a target
	void takeDamage(unsigned int amount); // Method to take damage
	void beRepaired(unsigned int amount); // Method to repair itself

	const std::string& getName() const; // Getter for name
	unsigned int getHitPoints() const; // Getter for hit points
	unsigned int getEnergyPoints() const; // Getter for energy points
	unsigned int getAttackDamage() const; // Getter for attack damage
	void setName(const std::string& name); // Setter for name

};
// Overloaded output operator for ClapTrap
std::ostream& operator<<(std::ostream& os, const ClapTrap& clapTrap);

#endif // CLAPTRAP_HPP