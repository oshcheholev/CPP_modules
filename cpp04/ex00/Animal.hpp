#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

#define GREEN "\033[32m"
#define YELLOW "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

class Animal {
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal& other);
		virtual ~Animal();

		Animal& operator=(const Animal& other);

		virtual void makeSound() const;
		std::string getType() const;
};
std::ostream& operator<<(std::ostream& os, const Animal& animal);

#endif 
