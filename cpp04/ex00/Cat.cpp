#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	this->type = "Cat";
	std::cout << MAGENTA << "New Cat was born!" << RESET << std::endl;
}  // Constructor
Cat::Cat(const Cat& other) : Animal(other) {
	this->type = other.type;
	std::cout << MAGENTA << "Cat " << other.type 
	<< " is copied." << RESET << std::endl;
}  // Copy constructor
Cat::~Cat() {
	std::cout << MAGENTA << "Cat " << this->type 
	<< " is gone. So it goes..." << RESET << std::endl;
}  // Destructor
Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}  // Assignment operator
void Cat::makeSound() const {
	std::cout << MAGENTA << " 😺  Meow! Meow!  😺" << RESET << std::endl;
}  // Override makeSound

std::ostream& operator<<(std::ostream& os, const Cat& cat) {
	os << MAGENTA << "Cat type: " << RESET << cat.getType();
	return os;
}  