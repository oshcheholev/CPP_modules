#include "AAnimal.hpp"

#include <iostream>
AAnimal::AAnimal() {
	this->type = "AAnimal";
	std::cout << GREEN << "New AAnimal was born!" << RESET << std::endl;
}	// Constructor

AAnimal::AAnimal(const AAnimal& other) {
	std::cout << GREEN << "AAnimal " << other.type 
	<< " is copied." << RESET << std::endl;
	this->type = other.type;
}	// Copy constructor

AAnimal::~AAnimal() {
	std::cout << GREEN << "AAnimal " << this->type 
	<< " is gone. So it goes..." << RESET << std::endl;
}	// Destructor

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}	// Assignment operator

// void AAnimal::makeSound() const {
// 	std::cout << GREEN << "Weird Undistinct Sound" << RESET << std::endl;
// }	

std::string AAnimal::getType() const {
	return this->type;
}	// Getter for type

std::ostream& operator<<(std::ostream& os, const AAnimal& AAnimal) {
	os << GREEN << "AAnimal type: " << RESET << AAnimal.getType();
	return os;
}	// Overloaded operator<< for AAnimal