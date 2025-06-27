#include "Animal.hpp"
#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void printTitle(const std::string& title) {
	std::cout << "\n" << BLUE << "--- " << title << " ---" << RESET << std::endl;
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;
}

int main() {

	printTitle("TEST FROM SUBJECT");
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	printTitle("TEST OF WRONG ANIMALS");
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* wrongi = new WrongCat();
	std::cout << wrongi->getType() << " " << std::endl;
	wrongi->makeSound(); //will output the cat sound!
	wrongmeta->makeSound();

	delete wrongmeta;
	delete wrongi;

	printTitle("ANIMAL  CLASS  TEST");
	Animal* animal = new Animal();
	std::cout << *animal << std::endl;
	animal->makeSound();
	delete animal;
	
	printTitle("CAT  CLASS  TEST");
	Cat* cat = new Cat();
	std::cout << *cat << std::endl;
	cat->makeSound();
	delete cat;

	printTitle("DOG  CLASS  TEST");
	Dog* dog = new Dog();
	std::cout << *dog << std::endl;
	dog->makeSound();
	delete dog;

	printTitle("WRONG ANIMAL CLASS TEST");
	WrongAnimal* wrongAnimal = new WrongAnimal();
	std::cout << *wrongAnimal << std::endl;
	wrongAnimal->makeSound();
	delete wrongAnimal;

	printTitle("WRONG CAT CLASS TEST");
	WrongCat* wrongCat = new WrongCat();
	std::cout << *wrongCat << std::endl;
	wrongCat->getType();
	wrongCat->makeSound();
	delete wrongCat;

	return 0;
}