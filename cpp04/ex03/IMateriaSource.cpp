#include <iostream>
#include "IMateriaSource.hpp"


// IMateriaSource::IMateriaSource() {
// 	std::cout << "IMateriaSource created." << std::endl;
// }
// IMateriaSource::~IMateriaSource() {
// 	std::cout << "IMateriaSource destroyed." << std::endl;
// }

// void IMateriaSource::learnMateria(AMateria* materia) {
// 	if (materia) {
// 		std::cout << "Learning materia of type: " << materia->getType() << std::endl;
// 		if (this->_materiaCount >= 4) {
// 			std::cerr << "Materia source is full, cannot learn more materia." << std::endl;
// 			return; // Do not learn if already full
// 		}
// 		this->_materia[this->_materiaCount] = materia->clone();
// 		this->_materiaCount++;
// 	}
// 	else {
// 		std::cerr << "Cannot learn null materia." << std::endl;
// 	}
// }
// AMateria* IMateriaSource::createMateria(std::string const & type) {
// 	for (int i = 0; i < this->_materiaCount; ++i) {
// 		if (this->_materia[i] && this->_materia[i]->getType() == type) {
// 			std::cout << "Creating materia of type: " << type << std::endl;
// 			return this->_materia[i]->clone();
// 		}
// 	}
// 	std::cerr << "Materia of type " << type << " not found." << std::endl;
// 	return NULL; // Return null if type not found
// }
