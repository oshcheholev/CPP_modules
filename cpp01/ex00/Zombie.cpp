#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "JustZombie";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}
Zombie::~Zombie()
{
	std::cout << this->name << " is dead. So it goes..." << std::endl;
}
void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string name)
{
	this->name = name;
}
std::string Zombie::getName(void)
{
	return this->name;
}

// The constructor initializes the name to "JustZombie" if no name is provided.
// The destructor prints a message when the Zombie object is destroyed.
// The announce method prints the zombie's name followed by a sound.
// The setName method allows you to change the name of the zombie.
// The getName method returns the current name of the zombie.
