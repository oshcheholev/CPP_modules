#include "Cat.hpp"
#include <iostream>

Cat::Cat() : _brain(new Brain()) {
	this->type = "Cat";
	std::cout << MAGENTA << "New Cat was born!" << RESET << std::endl;
}  // Constructor
Cat::Cat(const Cat& other) : Animal(other) {
	this->_brain = new Brain(*other._brain); // Deep copy of Brain
	this->type = other.type;
	std::cout << MAGENTA << "Cat " << other.type 
	<< " is copied." << RESET << std::endl;
}  // Copy constructor
Cat::~Cat() {
	std::cout << MAGENTA << "Cat " << this->type 
	<< " is gone. So it goes..." << RESET << std::endl;
	delete _brain; // Clean up Brain memory
	//_brain = null;
}  // Destructor
Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->type = other.type;
	}
	this->_brain = new Brain(*other._brain); // Deep copy of Brain
	return *this;
}  // Assignment operator
void Cat::makeSound() const {
	std::cout << MAGENTA << " 😺  Meow! Meow!  😺" << RESET << std::endl;
}  // Override makeSound

Brain* Cat::getBrain() const {
	return _brain; // Return pointer to Brain
}

void Cat::getIdeaFromBrain(int index) const {
//	_brain->getIdea(index) << std::endl;
	if (_brain) {
		std::cout << "Cat's idea at index " << index << ": " 
		          << _brain->getIdea(index) << std::endl;
	} else {
		std::cerr << "Cat has no brain!" << std::endl;
	}
}

void Cat::setIdeaToBrain(int index, const std::string& idea) {
	if (_brain) {
		_brain->setIdea(index, idea);
	} else {
		std::cerr << "Cat has no brain to set ideas!" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Cat& cat) {
	os << MAGENTA << "Cat type: " << RESET << cat.getType();
	return os;
}  