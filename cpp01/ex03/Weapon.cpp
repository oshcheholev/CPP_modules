#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

Weapon::Weapon(const std::string& type) : type(type)
{
}
Weapon::~Weapon()
{
}
const std::string& Weapon::getType() const
{
	return this->type;
}

void Weapon::setType(const std::string& type)
{
	std::cout << "Weapon " << this->type << " switched to " << type << std::endl;
	this->type = type;
}
