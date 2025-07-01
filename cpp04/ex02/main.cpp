#include "AAnimal.hpp"
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

	printTitle("TEST ABSTRACT ANIMAL CLASS");

//	AAnimal* meta = new AAnimal();
// We cannot instantiate an abstract class AAnimal directly,
// so we will use the derived classes Cat and Dog instead.
	AAnimal* j = new Dog();
	AAnimal* i = new Cat();



	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	delete j;
	delete i;

	printTitle("TEST OF STACK ANIMALS");
//	AAnimal animal;
// We cannot instantiate an abstract class AAnimal directly,
// so we will use the derived classes Cat and Dog instead.
	Dog dog;
	Cat cat;
	std::cout << dog << std::endl;
	std::cout << cat << std::endl;
	dog.makeSound();
	cat.makeSound();

	return 0;
}