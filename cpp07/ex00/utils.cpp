#include <iostream>
#include "utils.hpp"

void printTitle(const std::string& title) {
	std::cout << "\n" << BLUE 
	<< "--- "<< BOLD << title << " ---" 
	<< RESET << std::endl;
	
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;
}
