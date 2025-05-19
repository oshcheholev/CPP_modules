#include "Zombie.hpp"

Zombie* newZombie(std::string name) // Function to create a new Zombie
{
	return new Zombie(name);
}