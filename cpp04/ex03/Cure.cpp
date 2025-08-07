#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	this->type = "cure"; // Initialize the type to "cure"
	std::cout << "Cure materia created." << std::endl;
}
Cure::Cure(const Cure& other) : AMateria(other) {
	this->type = other.type; // Copy the type from the other Cure materia
	std::cout << "Cure materia copied." << std::endl;
}
Cure::~Cure() {
	std::cout << "Cure materia destroyed from Cure destructor." << std::endl;
}
Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << "Cure materia assigned." << std::endl;
	}
	return *this;
}
void Cure::use(ICharacter& target) const {
	std::cout << YELLOW <<"* heals " << target.getName() << "’s wounds *" << RESET << std::endl;
}
AMateria* Cure::clone() const {
	std::cout << "Cloning Cure materia." << std::endl;
	return new Cure(*this);
}
