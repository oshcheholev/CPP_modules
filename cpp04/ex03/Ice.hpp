#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice& other);
	~Ice();
	Ice& operator=(const Ice& other);
	AMateria* clone() const;
	void use(ICharacter& target) const;
};
std::ostream& operator<<(std::ostream& os, const Ice& ice);

#endif // ICE_HPP