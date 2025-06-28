#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>


class FragTrap : virtual public ClapTrap {
// Inherits from ClapTrap to use its members and methods
// This allows FragTrap to have the same properties as ClapTrap
protected:
	// std::string _name;
	// unsigned int _hitPoints;
	// unsigned int _energyPoints;
	// unsigned int _attackDamage;
public:
	// Constructors and Destructor	
	FragTrap(); // Default constructor
	FragTrap(const FragTrap &other); // Parameterized constructor
	FragTrap(const std::string &name); // Parameterized constructor
	~FragTrap(); // Destructor

	FragTrap &operator=(const FragTrap &other); // Copy assignment operator

	// Member functions
	void attack(const std::string &target); // Method to attack a target
	void highFivesGuys(void); // Method to enter guard mode

	// Getters and Setters
	const std::string& getName() const; // Getter for name
	unsigned int getHitPoints() const; // Getter for hit points
	unsigned int getEnergyPoints() const; // Getter for energy points
	unsigned int getAttackDamage() const; // Getter for attack damage
};

// Overloaded output operator for Frag
std::ostream &operator<<(std::ostream &os, const FragTrap &FragTrap);

#endif // FRAGTRAP_HPP
