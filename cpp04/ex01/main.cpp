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

	int size = 10;
	Animal* animals[size];
	for (int i = 0; i < size; i++) {
		if (i < size / 2) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}
	for (int i = 0; i < size; i++) {
		std::cout << animals[i]->getType() << " ";
		animals[i]->makeSound();
	}
	for (int i = 0; i < size; i++) {
		delete animals[i];
	}

	
	printTitle("CAT  CLASS  TEST");
	Cat* cat = new Cat();
	std::cout << *cat << std::endl;
	cat->makeSound();
	cat->setIdeaToBrain(0, "I want to rule the world!");
	cat->getIdeaFromBrain(0);
	cat->setIdeaToBrain(1, "I want to sleep on the couch!");
	cat->getIdeaFromBrain(1);
	cat->getIdeaFromBrain(2); 
	cat->getIdeaFromBrain(100);
	cat->getBrain()->setIdea(99, "I want to chase mice!");
//	std::cout << "Cat's brain: " << *cat->getBrain() << std::endl;
	printTitle("CAT COPY TEST");
	Cat* catCopy = new Cat(*cat);
	catCopy->setIdeaToBrain(0, "I want to eat Whiskas!");
	catCopy->setIdeaToBrain(1, "I want to catch a laser pointer!");
	std::cout << "Original Cat's brain: " << *cat->getBrain() << std::endl;
	// copy
	std::cout << "Copy of Cat's brain: " << *catCopy->getBrain() << std::endl;
	catCopy->getIdeaFromBrain(0);
	catCopy->getIdeaFromBrain(1);
	
	delete cat;
	delete catCopy;

	printTitle("DOG  CLASS  TEST");
	Dog* dog = new Dog();
	std::cout << *dog << std::endl;
	dog->makeSound();
	dog->setIdeaToBrain(0, "I want to fetch the ball!");
	dog->getIdeaFromBrain(0);
	dog->setIdeaToBrain(1, "I want to bark at the mailman!");
	dog->getIdeaFromBrain(1);
	dog->getIdeaFromBrain(2);
	dog->getIdeaFromBrain(100);
	dog->getBrain()->setIdea(99, "I want to dig a hole in the yard!");
//	std::cout << "Dog's brain: " << *dog->getBrain() << std::endl;		
	printTitle("DOG COPY TEST");
	Dog* dogCopy = new Dog(*dog);
	dogCopy->setIdeaToBrain(0, "I want to chase my tail!");
	dogCopy->setIdeaToBrain(1, "I want to bark at the moon!");
	std::cout << "Original Dog's brain: " << *dog->getBrain() << std::endl;
	// copy
	std::cout << "Copy of Dog's brain: " << *dogCopy->getBrain() << std::endl;
	dogCopy->getIdeaFromBrain(0);
	dogCopy->getIdeaFromBrain(1);	
	delete dog;
	delete dogCopy;


	return 0;
}