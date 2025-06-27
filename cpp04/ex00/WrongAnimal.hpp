#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

#define YELLOW "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"


class WrongAnimal {
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& other);

		void makeSound() const;
		std::string getType() const;
};
std::ostream& operator<<(std::ostream& os, const WrongAnimal& animal);

#endif 
