#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>
#include <string>

ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << BLUE << _name << RESET << " appears somewhere in Borderlands" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << BLUE << _name << RESET << " appears somewhere in Borderlands" << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "ScavTrap " << BLUE << _name << RESET << ", the copy of " << BLUE << other._name << RESET << " appears somewhere in Borderlands" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << BLUE << _name << RESET << " is dead. So it goes..." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ScavTrap " << BLUE << _name << RESET << " copied something from the other" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "ScavTrap " << BLUE << _name << RESET << " is too weak to attack. Shame on him!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << BLUE << ClapTrap::_name << RESET << " suddenly hit " << RED << target << RESET
	          << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	if (_hitPoints <= 0) {
		std::cout << "ScavTrap " << BLUE << _name << RESET << " is already destroyed. What do you want from him?" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << BLUE << _name << RESET << " is now in guard mode! " << RED << " YOU SHALL NOT PASS!!! " << RESET << std::endl;
}

// std::ostream& operator<<(std::ostream& os, const ScavTrap& scavTrap) {
// 	os << "ScavTrap " << BLUE << scavTrap._name << RESET
// 	   << " [Hit Points: " << scavTrap._hitPoints
// 	   << ", Energy Points: " << scavTrap._energyPoints
// 	   << ", Attack Damage: " << scavTrap._attackDamage << "]";
// 	return os;
// }