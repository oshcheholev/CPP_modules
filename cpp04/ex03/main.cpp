#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>


// #define GREEN "\033[32m"
// #define YELLOW "\033[32m"
// #define RED "\033[31m"
// #define BLUE "\033[34m"
// #define RESET "\033[0m"
// #define MAGENTA "\033[35m"
// #define CYAN "\033[36m"


void printTitle(const std::string& title) {
	std::cout << "\n" << BLUE << "--- " << title << " ---" << RESET << std::endl;
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;
}

int main() {

	printTitle("TEST FROM SUBJECT");
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
//return 0;


printTitle("More tests");
src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
me = new Character("Drucilla");

tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
tmp = src->createMateria("ice");
me->equip(tmp);

ICharacter* ed = new Character("Eduardo");
me->use(0, *ed);
me->use(1, *ed);
me->use(2, *ed);
me->use(3, *ed); 

// Save addresses before unequipping to avoid memory leaks
Character* meChar = static_cast<Character*>(me); // Cast to access getMateria method
AMateria* floor0 = meChar->getMateria(0); // Save address before unequipping
AMateria* floor1 = meChar->getMateria(1); // Save address before unequipping  
AMateria* floor2 = meChar->getMateria(2); // Save address before unequipping

me->unequip(0);
me->unequip(1); 
me->unequip(2);
tmp = src->createMateria("ice"); // Create a new materia instead of using old tmp
me->equip(tmp);
me->use(0, *ed); 
me->use(1, *ed); 
me->use(2, *ed); 
me->use(3, *ed);
tmp = src->createMateria("ice");
me->equip(tmp);
me->use(1, *ed);

// Clean up the materias left on the floor
delete floor0;
delete floor1;
delete floor2;
delete ed;
delete me;
delete src;

return 0;
}

