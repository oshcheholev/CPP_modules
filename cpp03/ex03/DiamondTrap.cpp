#include <iostream>
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("NoName_clap_name"), ScavTrap(), FragTrap(), _name("NoName") {
    // _hitPoints = 100;      // FragTrap's hit points
    // _energyPoints = 50;    // ScavTrap's energy points
    // _attackDamage = 30;    // FragTrap's attack damage
    _hitPoints = FragTrap::_hitPoints; // FragTrap's hit points
	_energyPoints = ScavTrap::_energyPoints; // ScavTrap's energy points
	_attackDamage = FragTrap::_attackDamage; // FragTrap's attack damage

	std::cout << "DiamondTrap " << MAGENTA << _name << RESET << " appears somewhere in Borderlands" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
    _hitPoints = FragTrap::_hitPoints; // FragTrap's hit points
	_energyPoints = ScavTrap::_energyPoints; // ScavTrap's energy points
	_attackDamage = FragTrap::_attackDamage; // FragTrap's attack damage
    std::cout << "DiamondTrap " << MAGENTA << _name << RESET << " appears somewhere in Borderlands" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "DiamondTrap " << MAGENTA << _name << RESET << ", the copy of " << MAGENTA << other._name << RESET << " appears somewhere in Borderlands" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "DiamondTrap " << MAGENTA << _name << RESET << " copied something from the other" << std::endl;
    return *this;
}
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << MAGENTA << _name << RESET << " is dead. So it goes..." << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
 ScavTrap::attack(target);
}

const std::string& DiamondTrap::getName() const {
	return _name;
}
unsigned int DiamondTrap::getHitPoints() const {
	return _hitPoints;
}
unsigned int DiamondTrap::getEnergyPoints() const {
	return _energyPoints;
}
unsigned int DiamondTrap::getAttackDamage() const {
	return _attackDamage;
}
void DiamondTrap::setName(const std::string& name) {
	_name = name;
	std::cout << "DiamondTrap name set to: " << MAGENTA << _name << RESET << std::endl;
	ClapTrap::_name = name + "_clap_name"; // Update ClapTrap's name
}

void DiamondTrap::whoAmI() {
	std::cout << "I AM DiamondTrap " << MAGENTA << _name << RESET 
	          << ", and my ClapTrap name is: " << GREEN << this->ClapTrap::_name << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& os, const DiamondTrap& diamondTrap) {
	os << "DiamondTrap Name: " << MAGENTA << diamondTrap.getName() << RESET
	   << ", Hit Points: " << diamondTrap.getHitPoints()
	   << ", Energy Points: " << diamondTrap.getEnergyPoints()
	   << ", Attack Damage: " << diamondTrap.getAttackDamage();
	return os;
}

