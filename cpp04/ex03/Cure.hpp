#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure& other);
	~Cure();
	Cure& operator=(const Cure& other);
	AMateria* clone() const;
	void use(ICharacter& target) const;
};
std::ostream& operator<<(std::ostream& os, const Cure& Cure);

#endif // Cure_HPP