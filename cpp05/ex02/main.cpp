
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



void printTitle(const std::string& title) {
	std::cout << "\n" << BLUE << "--- " << title << " ---" << RESET << std::endl;
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;
}

int main() {


	printTitle("Shrubbery Creation Form Test with Bureaucrat too low to execute");
	try {
		Bureaucrat bureaucrat("Eduardo", 160);
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

	printTitle("Shrubbery Creation Form Test with normal Bureaucrat");
	try {
		Bureaucrat bureaucrat("Eduardo", 150);
		std::cout << bureaucrat << std::endl;
		ShrubberyCreationForm form("Garden");
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << "Is form signed? " << (form.isSigned() ? "Yes" : "No") << std::endl; // Check if form is signed
		bureaucrat.setGrade(145); // Set grade to sign
		bureaucrat.signForm(form);
		std::cout << "Is form signed? " << (form.isSigned() ? "Yes" : "No") << std::endl; // Check if form is signed
		std::cout << "Executing form..." << std::endl;
		std::cout << form << std::endl;
		form.execute(bureaucrat);
		bureaucrat.setGrade(137); // Set grade to allow execution
		form.execute(bureaucrat);
	} catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	printTitle("Robotomy Request Form Test");
	try {
		Bureaucrat bureaucrat("Felix", 100);
		std::cout << bureaucrat << std::endl;
		RobotomyRequestForm form("Bender");
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << "Is form signed? " << (form.isSigned() ? "Yes" : "No") << std::endl; // Check if form is signed
		bureaucrat.setGrade(50); // Set grade to sign
		bureaucrat.signForm(form);
		std::cout << "Is form signed? " << (form.isSigned() ? "Yes" : "No") << std::endl; // Check if form is signed

		std::cout << form << std::endl;
		form.execute(bureaucrat);
		bureaucrat.setGrade(30); // Set grade to allow execution
		form.execute(bureaucrat);
	} catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	printTitle("Presidential Pardon Form Test");
	try {
		Bureaucrat bureaucrat("Drucilla", 40);
		std::cout << bureaucrat << std::endl;
		PresidentialPardonForm form("John Doe");
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.setGrade(10); // Set grade to allow execution
		bureaucrat.signForm(form);
		std::cout << form.isSigned() << std::endl; // Check if form is signed
		std::cout << form << std::endl;
		std::cout << "Executing form..." << std::endl;
		form.execute(bureaucrat);
		bureaucrat.setGrade(4);
		std::cout << form << std::endl;
		form.execute(bureaucrat);
	} catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}



	return 0;
}

