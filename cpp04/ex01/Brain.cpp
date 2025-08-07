#include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain() {
	std::cout << "The Brain born with it's owner!" << std::endl;
	for (int i = 0; i < 100; ++i) {
		ideas[i] = "Just idea";
	}
}
Brain::Brain(const Brain& other) {
	std::cout << "Brain copied!" << std::endl;
	*this = other; // Use assignment operator to copy ideas
}
Brain::~Brain() {
	std::cout << "Brain gone with it's owner" << std::endl;
}
Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain ideas copied!" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}
void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100) {
		ideas[index] = idea;
	} else {
		std::cerr << "I have ideas from 0 to 99" << std::endl;
	}
}
std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return ideas[index];
	} 
	else {
		std::cerr << "I have ideas from 0 to 99" << std::endl;
		return "";
	}
}
std::ostream& operator<<(std::ostream& os, const Brain& brain) {
	os << "Brain ideas: ";
	for (int i = 0; i < 100; ++i) {
		os << "[" << i << "] " << brain.getIdea(i) << " ";
	}
	return os;
}

