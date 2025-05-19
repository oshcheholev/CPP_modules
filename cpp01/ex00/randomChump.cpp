#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}
// The randomChump function creates a Zombie object with the given name and calls its announce method.