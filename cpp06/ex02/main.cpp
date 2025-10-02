#include "Base.hpp"
#include <ctime> // for time()
#include <cstdlib>  // for rand(), srand()


#include <iostream>

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"


void printTitle(const std::string& title) {
	std::cout << "\n" << BLUE << "--- " << title << " ---" << RESET << std::endl;
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;
}



int main(void) {
	srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    for (int i = 0; i < 5; ++i) {
        printTitle("Random Object Generation");
        Base* obj = generate();
        if (obj) {
            identify(obj);
            identify(*obj);
            delete obj;
        }
    }
    return 0;
}

