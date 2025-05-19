#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	Zombie *zombie = new Zombie();
	zombie->announce();
	delete zombie;
	Zombie *zombies = new Zombie[5];
	for (int i = 0; i < 5; i++)
	{
		zombies[i].setName("Zombie");
		zombies[i].announce();
	}
	delete[] zombies;

	Zombie *newZ = newZombie("NewZombie");
	newZ->announce();
	delete newZ;

	randomChump("RandomChump");
	return (0);
}