#include "WrongAnimal.hpp"

#include <iostream>


WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
	std::cout << YELLOW << "New WrongAnimal was born!" << RESET << std::endl;
}	// Constructor

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << YELLOW << "WrongAnimal " << other.type 
	<< " is copied." << RESET << std::endl;
	this->type = other.type;
}	// Copy constructor

WrongAnimal::~WrongAnimal() {
	std::cout << YELLOW << "WrongAnimal " << this->type 
	<< " is gone. So it goes..." << RESET << std::endl;
}	// Destructor

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}	// Assignment operator

void WrongAnimal::makeSound() const {
	std::cout << YELLOW 
	<< "Wrong Undistinct Sound" 
	<< RESET << std::endl;
}	

std::string WrongAnimal::getType() const {
	return this->type;
}	// Getter for type

std::ostream& operator<<(std::ostream& os, const WrongAnimal& WrongAnimal) {
	os << YELLOW << "WrongAnimal type: " << RESET << WrongAnimal.getType();
	return os;
}	// Overloaded operator<< for WrongAnimal