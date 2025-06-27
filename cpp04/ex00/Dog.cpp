#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
	this->type = "Dog";
	std::cout << CYAN << "New Dog was born!" << RESET << std::endl;
}  // Constructor
Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << CYAN << "Dog " << other.type 
	<< " is copied." << RESET << std::endl;
}  // Copy constructor
Dog::~Dog() {
	std::cout << CYAN << "Dog " << this->type 
	<< " is gone. So it goes..." << RESET << std::endl;
}  // Destructor
Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}  // Assignment operator
void Dog::makeSound() const {
	std::cout << CYAN << "🐶   Woof! Woof!   🐶" << RESET << std::endl;
}  // Override makeSound

std::ostream& operator<<(std::ostream& os, const Dog& Dog) {
	os << CYAN << "Dog type: " << RESET << Dog.getType();
	return os;
}  