#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << MAGENTA << "New WrongCat was born!" << RESET << std::endl;
}  // Constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << MAGENTA << "WrongCat " << other.type 
	<< " is copied." << RESET << std::endl;
}  // Copy constructor
WrongCat::~WrongCat() {
	std::cout << MAGENTA << "WrongCat " << this->type 
	<< " is gone. So it goes..." << RESET << std::endl;
}  // Destructor
WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}  // Assignment operator
// void WrongCat::makeSound() const {
// 	std::cout << MAGENTA << " 😺  Meow! Meow!  😺" << RESET << std::endl;
// }  // Override makeSound

std::ostream& operator<<(std::ostream& os, const WrongCat& WrongCat) {
	os << MAGENTA << "WrongCat type: " << RESET << WrongCat.getType();
	return os;
}  