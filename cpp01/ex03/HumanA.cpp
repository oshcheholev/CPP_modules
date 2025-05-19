#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon) :
    _name(name), _weapon(weapon)
{
}

void HumanA::setWeapon(Weapon& weapon)
{
	std::cout 	<< this->_name
				<< " changes weapon to " 
				<< weapon.getType() << std::endl;
	this->_weapon = weapon;
}

void HumanA::attack() const
{
	std::cout 	<< this->_name 
				<< " attacks with their "
	        	<< this->_weapon.getType() << std::endl;
}