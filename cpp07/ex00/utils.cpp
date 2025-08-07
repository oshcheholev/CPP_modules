#include "utils.hpp"
#include <iostream>

void printTitle(const std::string& title) {
	std::cout << "\n" << BLUE 
	<< "--- "<< BOLD << title << " ---" 
	<< RESET << std::endl;
	
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;
}
