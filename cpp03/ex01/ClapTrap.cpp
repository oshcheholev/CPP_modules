#include "ClapTrap.hpp"


ClapTrap::ClapTrap() 
	: _name("John Doe"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Claptrap " << GREEN <<  _name << RESET << " appears somewhere in Borderlands"<<std::endl;
}

ClapTrap::ClapTrap(const std::string& name) 
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Claptrap " << GREEN <<  _name << RESET << " appears somewhere in Borderlands"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
	: _name(other._name), _hitPoints(other._hitPoints), 
	  _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cout << "Claptrap " << GREEN <<  _name << RESET << ", the copy of " << GREEN <<  other._name << RESET << " appears somewhere in Borderlands"<<std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Claptrap " << GREEN <<  _name << RESET << " is dead. So it goes..." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "Claptrap " << GREEN <<  _name << RESET << " copied something from the other. Good Boy!" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "ClapTrap " << GREEN <<  _name << RESET << " is too weak to attack. Shame on him!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << GREEN <<  _name << RESET << " suddenly hit " << RED << target << RESET
	          << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is already destroyed. What do you want from him?" << std::endl;
		return;
	}
	if (_hitPoints > amount) {
		std::cout << "ClapTrap " << GREEN <<  _name << RESET << " takes " << amount 
		          << " points of damage!" << std::endl;
		_hitPoints -= amount;
		std::cout << "Remaining hit points: " << _hitPoints << std::endl;
	} else {
		std::cout << "ClapTrap " << GREEN <<  _name << RESET << " is destroyed by taking " 
		          << amount << " points of damage!" << std::endl;
		_hitPoints = 0;
	}
//	_hitPoints = (_hitPoints > amount) ? (_hitPoints - amount) : 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "ClapTrap " << GREEN <<  _name << RESET " cannot be repaired because it is out of hit points or energy." << std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << GREEN <<  _name << RESET " repairs itself for " << amount 
	          << " points! New hit points: " << _hitPoints << std::endl;
}

const std::string& ClapTrap::getName() const {
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

void ClapTrap::setName(const std::string& name) {
	_name = name;
	std::cout << "ClapTrap's name has been set to " << GREEN << _name << RESET << std::endl;
}


std::ostream& operator<<(std::ostream& os, const ClapTrap& clapTrap) {
	os << "ClapTrap " << GREEN << clapTrap.getName() << RESET 
	   << " [Hit Points: " << clapTrap.getHitPoints() 
	   << ", Energy Points: " << clapTrap.getEnergyPoints() 
	   << ", Attack Damage: " << clapTrap.getAttackDamage() << "]";
	return os;
}