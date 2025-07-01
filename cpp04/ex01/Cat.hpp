#include "Animal.hpp"
#include "Brain.hpp"

#include <iostream>
class Cat : public Animal {
	private:
		Brain* _brain; // Pointer to Brain object for Cat's ideas
	public:
		Cat();
		Cat(const Cat& other);
		~Cat();
		Cat& operator=(const Cat& other);
		void makeSound() const;
		Brain* getBrain() const; // Getter for Brain pointer
		void getIdeaFromBrain(int index) const; // Get idea from Brain
		void setIdeaToBrain(int index, const std::string& idea); // Set idea
};
std::ostream& operator<<(std::ostream& os, const Cat& cat);