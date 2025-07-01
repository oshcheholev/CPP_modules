#include "AAnimal.hpp"
#include "Brain.hpp"

#include <iostream>
class Dog : public AAnimal {
	private:
		Brain* _brain;
	public:
		Dog();
		Dog(const Dog& other);
		~Dog();
		Dog& operator=(const Dog& other);
		void makeSound() const;
		Brain* getBrain() const; // Getter for Brain pointer
		void getIdeaFromBrain(int index) const; // Get idea from Brain
		void setIdeaToBrain(int index, const std::string& idea); // Set idea

};
std::ostream& operator<<(std::ostream& os, const Dog& Dog);