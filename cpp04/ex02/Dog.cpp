#include "Dog.hpp"
#include <iostream>

Dog::Dog() : AAnimal() {
	this->_brain = new Brain(); // Initialize Brain
	this->type = "Dog";
	std::cout << MAGENTA << "New Dog was born!" << RESET << std::endl;
}  // Constructor
Dog::Dog(const Dog& other) : AAnimal(other) {
	this->_brain = new Brain(*other._brain); // Deep copy of Brain
	this->type = other.type;
	std::cout << MAGENTA << "Dog " << other.type 
	<< " is copied." << RESET << std::endl;
}  // Copy constructor
Dog::~Dog() {
	std::cout << MAGENTA << "Dog " << this->type 
	<< " is gone. So it goes..." << RESET << std::endl;
	delete _brain; // Clean up Brain memory
	//_brain = null;
}  // Destructor
Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->type = other.type;
	}
	this->_brain = new Brain(*other._brain); // Deep copy of Brain
	return *this;
}  // Assignment operator
void Dog::makeSound() const {
	std::cout << MAGENTA << "🐶  Woof! Woof!  🐶" << RESET << std::endl;
}  // Override makeSound

Brain* Dog::getBrain() const {
	return _brain; // Return pointer to Brain
}

void Dog::getIdeaFromBrain(int index) const {
//	_brain->getIdea(index) << std::endl;
	if (_brain) {
		std::cout << "Dog's idea at index " << index << ": " 
		          << _brain->getIdea(index) << std::endl;
	} else {
		std::cerr << "Dog has no brain!" << std::endl;
	}
}

void Dog::setIdeaToBrain(int index, const std::string& idea) {
	if (_brain) {
		_brain->setIdea(index, idea);
	} else {
		std::cerr << "Dog has no brain to set ideas!" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Dog& Dog) {
	os << MAGENTA << "Dog type: " << RESET << Dog.getType();
	return os;
}  