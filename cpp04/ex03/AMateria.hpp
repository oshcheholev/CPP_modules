#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"


class AMateria {
protected:
	std::string type;
public:
	AMateria();
	AMateria(std::string const & type);
	virtual ~AMateria();
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0; // Pure virtual function for cloning
	virtual void use(ICharacter& target) const = 0; // Pure virtual function for using the materia
};

#endif // AMATERIA_HPP
