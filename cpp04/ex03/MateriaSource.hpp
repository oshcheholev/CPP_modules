#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>
class MateriaSource : public IMateriaSource {
private:
	AMateria* _materia[4]; // Array to hold learned materia
	int _materiaCount; // Count of learned materia
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	~MateriaSource();
	MateriaSource& operator=(const MateriaSource& other);
	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const & type);
};

#endif // MATERIASOURCE_HPP