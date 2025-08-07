#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice materia created." << std::endl;
}
Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << "Ice materia copied." << std::endl;
}
Ice::~Ice() {
	std::cout << "Ice materia destroyed from Ice destructor." << std::endl;
}
Ice& Ice::operator=(const Ice& other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << "Ice materia assigned." << std::endl;
	}
	return *this;
}
void Ice::use(ICharacter& target) const {
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
AMateria* Ice::clone() const {
	std::cout << "Cloning Ice materia." << std::endl;
	return new Ice(*this);
}
