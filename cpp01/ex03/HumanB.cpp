#include "HumanB.hpp"
#include "Weapon.hpp"

#include <iostream>
#include <string>

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon)
{
	std::cout   << this->_name 
				<< " changes weapon to " 
				<< weapon.getType() 
				<< std::endl;
	this->_weapon = &weapon;
}

void HumanB::attack() const
{
	if (this->_weapon) {
		std::cout   << this->_name 
					<< " attacks with their "
		        	<< this->_weapon->getType() << std::endl;
	}
	else {
		std::cout 	<< this->_name 
					<< " has no weapon to attack" << std::endl;
	}
}
