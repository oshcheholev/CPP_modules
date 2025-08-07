
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"




void printTitle(const std::string& title) {
	std::cout << "\n" << BLUE << "--- " << title << " ---" << RESET << std::endl;
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;
}

int main() {

	printTitle("Valid Bureaucrat operations");

	try {
		Bureaucrat bureaucrat("Druscilla", 50);
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;

		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;

		bureaucrat.setGrade(1);
		std::cout << bureaucrat << std::endl;

		bureaucrat.setName("Jane Doe");
		std::cout << bureaucrat << std::endl;
		bureaucrat.setGrade(150);
		std::cout << bureaucrat << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	printTitle("Bureaucrat with too high grade");
	try {
		Bureaucrat bureaucrat("Martha", 1); 
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();// exception
	} catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	printTitle("Bureaucrat with too low grade");
	try {
		Bureaucrat bureaucrat("Eduardo", 150); // exception
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade(); // exception
	} catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

return 0;
}

