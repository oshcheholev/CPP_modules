#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character() : _name("Default"), _inventorySize(0) {
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
}

Character::Character(const std::string& name) : _name(name), _inventorySize(0) {
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
	std::cout << "Character " << _name << " created." << std::endl;
}

Character::Character(const Character& other) : 
_name(other._name), _inventorySize(other._inventorySize) {
	for (int i = 0; i < 4; ++i) {
		if (other._inventory[i]) {
			_inventory[i] = other._inventory[i]->clone();
		} else {
			_inventory[i] = NULL;
		}
	}
}
Character& Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other._name;
		_inventorySize = other._inventorySize;
		for (int i = 0; i < 4; ++i) {
			delete _inventory[i]; // Clean up existing materia
			if (other._inventory[i]) {
				_inventory[i] = other._inventory[i]->clone();
			} else {
				_inventory[i] = NULL;
			}
		}
	}
	return *this;
}


Character::~Character() {
	// Clean up all remaining materias in inventory
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i]) {
			delete _inventory[i];
		}
	}
}
std::string const & Character::getName() const {
	return _name;
}
void Character::equip(AMateria* m) 
{
	if (!m) return;
	
	for (int i = 0; i < 4; ++i) {
		if (!_inventory[i]) { // Find an empty slot
			_inventory[i] = m; // Equip the materia
			_inventorySize++;
			std::cout << "Equipped " << m->getType() << " to " << _name << " at index " << i << std::endl;
			return;
		}
	}
	
	// If we reach here, inventory is full
	std::string type = m->getType(); // Store type before deleting
	std::cout << "Inventory full, cannot equip " << type << std::endl;
	delete m; // Clean up the materia if inventory is full
}
void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		_inventory[idx] = NULL; // Remove from inventory without deleting
		_inventorySize--;
	}
}
void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		_inventory[idx]->use(target);
	} else {
		std::cout << "Invalid index or no materia equipped at index " << idx << std::endl;
	}
}

AMateria* Character::getMateria(int idx) const {
	if (idx >= 0 && idx < 4) {
		return _inventory[idx];
	}
	return NULL;
}