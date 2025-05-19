#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	Zombie *zombie = new Zombie();
	zombie->announce();
	delete zombie;

	Zombie *zombie1 = new Zombie("Zombieeeeee");
	zombie1->announce();
	delete zombie1;

	Zombie *zombies = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}