#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _materiaCount(0) {
	std::cout << "MateriaSource created." << std::endl;
	for (int i = 0; i < 4; ++i) {
		_materia[i] = NULL;
	}
}
MateriaSource::MateriaSource(const MateriaSource& other) : _materiaCount(other._materiaCount) {
	std::cout << "MateriaSource copied." << std::endl;
	for (int i = 0; i < 4; ++i) {
		if (other._materia[i]) {
			_materia[i] = other._materia[i]->clone();
		} else {
			_materia[i] = NULL;
		}
	}
}
MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destroyed." << std::endl;
	for (int i = 0; i < _materiaCount; ++i) {
		delete _materia[i]; // Clean up materia
		_materia[i] = NULL;
	}
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		_materiaCount = other._materiaCount;
		for (int i = 0; i < 4; ++i) {
			delete _materia[i]; // Clean up existing materia
			if (other._materia[i]) {
				_materia[i] = other._materia[i]->clone();
			} else {
				_materia[i] = NULL;
			}
		}
	}
	return *this;
}
void MateriaSource::learnMateria(AMateria* materia) {
	if (materia && _materiaCount < 4) {
		_materia[_materiaCount++] = materia->clone();
		std::cout << "Learned materia of type: " << materia->getType() << std::endl;
	} else {
		std::cerr << "Cannot learn more materia or null materia." << std::endl;
	}
}
AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < _materiaCount; ++i) {
		if (_materia[i] && _materia[i]->getType() == type) {
			std::cout << "Creating materia of type: " << type << std::endl;
			return _materia[i]->clone();
		}
	}
	std::cerr << "Materia of type " << type << " not found." << std::endl;
	return NULL; // Return null if type not found
}
