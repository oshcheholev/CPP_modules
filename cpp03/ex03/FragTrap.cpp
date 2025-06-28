#include "ClapTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>
#include <string>

FragTrap::FragTrap() : ClapTrap("FragTrap") {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "FragTrap " << YELLOW << _name << RESET << " appears somewhere in Borderlands" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "FragTrap " << YELLOW << _name << RESET << " appears somewhere in Borderlands" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "FragTrap " << YELLOW << _name << RESET << ", the copy of " << YELLOW << other._name << RESET << " appears somewhere in Borderlands" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << YELLOW << _name << RESET << " is dead. So it goes..." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "FragTrap " << YELLOW << _name << RESET << " copied all from the other" << std::endl;
	return *this;
}

void FragTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "FragTrap " << YELLOW << _name << RESET << " is too weak to attack. Shame on him!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "FragTrap " << YELLOW << _name << RESET << " suddenly hit " << RED << target << RESET
	          << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// void FragTrap::highFivesGuys() {
// 	if (_hitPoints <= 0) {
// 		std::cout << "FragTrap " << YELLOW << _name << RESET << " is already destroyed. What do you want from him?" << std::endl;
// 		return;
// 	}
// 	std::cout << "FragTrap " << YELLOW << _name << RESET << " gives a high five!" << std::endl;
// }
void FragTrap::highFivesGuys(void) {
    std::cout << YELLOW
              << _name << ": \n"
              << "    o/\n"
              << "   /|\n"
              << "    |\n"
              << "   / \\\n"
              << "HIGH FIVE!\n"
              << RESET << std::endl;
}
const std::string& FragTrap::getName() const {
	return _name;
}
unsigned int FragTrap::getHitPoints() const {
	return _hitPoints;
}
unsigned int FragTrap::getEnergyPoints() const {
	return _energyPoints;
}
unsigned int FragTrap::getAttackDamage() const {
	return _attackDamage;
}

std::ostream& operator<<(std::ostream& os, const FragTrap& FragTrap) {
	os << "FragTrap " << YELLOW << FragTrap.getName() << RESET
	   << " [Hit Points: " << FragTrap.getHitPoints()
	   << ", Energy Points: " << FragTrap.getEnergyPoints()
	   << ", Attack Damage: " << FragTrap.getAttackDamage() << "]" << std::endl;
	return os;
}