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
	// Virtual destructor for proper cleanup of derived classes
}
std::string const & Character::getName() const {
	return _name;
}
void Character::equip(AMateria* m) {
	if (_inventorySize < 4 && m) {
		_inventory[_inventorySize++] = m;
	}
}
void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		delete _inventory[idx]; // Clean up the materia
		_inventory[idx] = NULL;
		// Shift remaining materia to fill the gap
		for (int i = idx; i < _inventorySize - 1; ++i) {
			_inventory[i] = _inventory[i + 1];
		}
		_inventory[--_inventorySize] = NULL; // Decrease size and nullify last element
	}
}
void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < _inventorySize && _inventory[idx]) {
		_inventory[idx]->use(target);
	} else {
		std::cout << "Invalid index or no materia equipped at index " << idx << std::endl;
	}
}