
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"



void printTitle(const std::string& title) {
	std::cout << "\n" << BLUE << "--- " << title << " ---" << RESET << std::endl;
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;
}

int main() {

	printTitle("Shrubbery Creation Form Test");
	try {
		Bureaucrat bureaucrat("Alice", 50);
		std::cout << bureaucrat << std::endl;
		ShrubberyCreationForm form("Garden");
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		form.execute(bureaucrat);
		std::cout << "Shrubbery created successfully." << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	printTitle("Robotomy Request Form Test");
	try {
		Bureaucrat bureaucrat("Bob", 30);
		std::cout << bureaucrat << std::endl;
		RobotomyRequestForm form("Robot");
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		form.execute(bureaucrat);
		std::cout << "Robotomy request executed successfully." << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// try {
	// 	Bureaucrat bureaucrat("Druscilla", 50);
	// 	std::cout << bureaucrat << std::endl;
	// } catch (std::exception &e) {
	// 	std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	// }
	// printTitle("Invalid Bureaucrat operations");
	// try {
	// 	Bureaucrat bureaucrat("Druscilla", 0); // Invalid grade
	// 	std::cout << bureaucrat << std::endl;
	// } catch (std::exception &e) {
	// 	std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	// }
	// printTitle("Valid Form operations");
	// try {
	// 	Bureaucrat bureaucrat("Druscilla", 50);
	// 	std::cout << form << std::endl;
	// 	bureaucrat.signForm(form);
	// 	std::cout << form << std::endl;
	// } catch (std::exception &e) {
	// 	std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	// }
	// printTitle("Invalid Form operations");
	// try {
	// 	Bureaucrat bureaucrat("Druscilla", 50);
	// 	Form form("Form2", 20, 20); // Form with high sign grade
	// 	std::cout << form << std::endl;
	// 	bureaucrat.signForm(form); // Should throw an exception
	// 	std::cout << form << std::endl;
	// } catch (std::exception &e) {
	// 	std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	// }
	// printTitle("Form with low execute grade");
	// try {
	// 	Bureaucrat bureaucrat("Druscilla", 50);
	// 	Form form("Form3", 50, 200); // Form with low execute grade
	// 	std::cout << form << std::endl;
	// 	bureaucrat.signForm(form); // Should throw an exception
	// 	std::cout << form << std::endl;
	// } catch (std::exception &e) {
	// 	std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	// }
	// printTitle("Form with high execute grade");
	// try {
	// 	Bureaucrat bureaucrat("Druscilla", 50);
	// 	Form form("Form4", 50, 0); // Form with high execute grade
	// 	std::cout << form << std::endl;
	// 	bureaucrat.signForm(form); // Should throw an exception
	// 	std::cout << form << std::endl;
	// } catch (std::exception &e) {
	// 	std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	// }

	// printTitle("Signing already signed form	");
	// try {
	// 	Bureaucrat bureaucrat("Druscilla", 50);
	// 	Form form("Form5", 50, 50);
	// 	std::cout << form << std::endl;
	// 	bureaucrat.signForm(form);
	// 	std::cout << form << std::endl;
	// 	bureaucrat.signForm(form); 
	// 	std::cout << form << std::endl;
	// } catch (std::exception &e) {
	// 	std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	// }


	return 0;
}

