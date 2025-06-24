#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : 
	_name("Default"), 
	_hitPoints(10), 
	_energyPoints(10), 
	_attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : 
	_name(name), 
	_hitPoints(10), 
	_energyPoints(10), 
	_attackDamage(0) {
	std::cout << "ClapTrap parameterized constructor called for " << name << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &src) :
	_name(src._name),
	_hitPoints(src._hitPoints),
	_energyPoints(src._energyPoints),
	_attackDamage(src._attackDamage) {
	std::cout << "ClapTrap copy constructor called for " << src._name << std::endl;
}
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called for " << _name << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	if (this != &rhs) {
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
		std::cout << "ClapTrap assignment operator called for " << _name << std::endl;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target 
		          << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else {
		std::cout << "ClapTrap " << _name << " cannot attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		_hitPoints -= amount;
		if (_hitPoints < 0) _hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount 
		          << " points of damage! Hit points left: " << _hitPoints << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " repairs itself for " 
		          << amount << " points! Hit points now: " << _hitPoints << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " cannot be repaired!" << std::endl;
	}
}

std::string ClapTrap::getName() const {
	return _name;
}
unsigned int ClapTrap::getHitPoints() const {
	return _hitPoints;
}
unsigned int ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}
unsigned int ClapTrap::getAttackDamage() const {
	return _attackDamage;
}
