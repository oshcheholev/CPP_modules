#include "AMateria.hpp"

AMateria::AMateria() : type("Unknown") {
	std::cout << "AMateria created with type: " << type << std::endl;
}
AMateria::AMateria(const std::string& type) : type(type) {
	std::cout << "AMateria created with type: " << type << std::endl;
}
AMateria::~AMateria() {
	std::cout << "AMateria of type " << type << " destroyed." << std::endl;
}
AMateria::AMateria(const AMateria& other) : type(other.type) {
	std::cout << "AMateria copied with type: " << type << std::endl;
}
AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << "AMateria assigned with type: " << type << std::endl;
	}
	return *this;
}

const std::string& AMateria::getType() const {
	return type;
}
