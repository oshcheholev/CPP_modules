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

class AAnimal {
	protected:
		std::string type;

	public:
		AAnimal();
		AAnimal(const AAnimal& other);
		virtual ~AAnimal();

		AAnimal& operator=(const AAnimal& other);

		virtual void makeSound() const = 0; // Pure virtual function
		// Making Animal an abstract class
		// so it cannot be instantiated directly;
		std::string getType() const;
};
std::ostream& operator<<(std::ostream& os, const AAnimal& AAnimal);

#endif 
