#include "Animal.hpp"

#include <iostream>
Animal::Animal() {
	this->type = "Animal";
	std::cout << GREEN << "New Animal was born!" << RESET << std::endl;
}	// Constructor

Animal::Animal(const Animal& other) {
	std::cout << GREEN << "Animal " << other.type 
	<< " is copied." << RESET << std::endl;
	this->type = other.type;
}	// Copy constructor

Animal::~Animal() {
	std::cout << GREEN << "Animal " << this->type 
	<< " is gone. So it goes..." << RESET << std::endl;
}	// Destructor

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}	// Assignment operator

void Animal::makeSound() const {
	std::cout << GREEN << "Weird Undistinct Sound" << RESET << std::endl;
}	

std::string Animal::getType() const {
	return this->type;
}	// Getter for type

std::ostream& operator<<(std::ostream& os, const Animal& animal) {
	os << GREEN << "Animal type: " << RESET << animal.getType();
	return os;
}	// Overloaded operator<< for Animal