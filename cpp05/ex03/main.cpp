
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"



void printTitle(const std::string& title) {
	std::cout << "\n" << BLUE << "--- " << title << " ---" << RESET << std::endl;
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;
}

int main() {

	printTitle("Intern test");
	Intern intern;
	std::cout << intern << std::endl;

	AForm* form1 = intern.makeForm("shrubbery creation", "Garden");
	AForm* form2 = intern.makeForm("robotomy request", "Robot");
	AForm* form3 = intern.makeForm("presidential pardon", "John Doe");
	
	AForm* form4 = intern.makeForm("unknown form", "Unknown");
	
	if (form1) {
		std::cout << *form1 << std::endl;
	}
	if (form2) {
		std::cout << *form2 << std::endl;
	}
	if (form3) {
		std::cout << *form3 << std::endl;
	}
	if (form4) {
		std::cout << *form4 << std::endl;
	}

// 	printTitle("Shrubbery Creation Form Test with Bureaucrat too low to execute");
// 	try {
// 		Bureaucrat bureaucrat("Eduardo", 160);
// 		std::cout << bureaucrat << std::endl;
// 		ShrubberyCreationForm form("Garden");
// 		std::cout << form << std::endl;
// 		bureaucrat.signForm(form);
// 		std::cout << form << std::endl;
// 		form.execute(bureaucrat);
// 		std::cout << "Shrubbery created successfully." << std::endl;
// 	} catch (std::exception &e) {
// 		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
// 	}

// 	printTitle("Shrubbery Creation Form Test with normal Bureaucrat");
// 	try {
// 		Bureaucrat bureaucrat("Eduardo", 150);
// 		std::cout << bureaucrat << std::endl;
// 		ShrubberyCreationForm form("Garden");
// 		std::cout << form << std::endl;
// 		bureaucrat.signForm(form);
// 		std::cout << "Is form signed? " << (form.isSigned() ? "Yes" : "No") << std::endl; // Check if form is signed
// 		bureaucrat.setGrade(145); // Set grade to sign
// 		bureaucrat.signForm(form);
// 		std::cout << "Is form signed? " << (form.isSigned() ? "Yes" : "No") << std::endl; // Check if form is signed
// 		std::cout << "Executing form..." << std::endl;
// 		std::cout << form << std::endl;
// 		form.execute(bureaucrat);
// 		bureaucrat.setGrade(137); // Set grade to allow execution
// 		form.execute(bureaucrat);
// //		std::cout << "Shrubbery created successfully." << std::endl;
// 	} catch (std::exception &e) {
// 		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
// 	}

// 	printTitle("Robotomy Request Form Test");
// 	try {
// 		Bureaucrat bureaucrat("Felix", 100);
// 		std::cout << bureaucrat << std::endl;
// 		RobotomyRequestForm form("Robot");
// 		std::cout << form << std::endl;
// 		bureaucrat.signForm(form);
// 		std::cout << "Is form signed? " << (form.isSigned() ? "Yes" : "No") << std::endl; // Check if form is signed
// 		bureaucrat.setGrade(50); // Set grade to sign
// 		bureaucrat.signForm(form);
// 		std::cout << "Is form signed? " << (form.isSigned() ? "Yes" : "No") << std::endl; // Check if form is signed

// 		std::cout << form << std::endl;
// 		form.execute(bureaucrat);
// 		bureaucrat.setGrade(30); // Set grade to allow execution
// 		form.execute(bureaucrat);
// 		//		std::cout << "Robotomy request executed successfully." << std::endl;
// 	} catch (std::exception &e) {
// 		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
// 	}

// 	printTitle("Presidential Pardon Form Test");
// 	try {
// 		Bureaucrat bureaucrat("Drucilla", 40);
// 		std::cout << bureaucrat << std::endl;
// 		PresidentialPardonForm form("John Doe");
// 		std::cout << form << std::endl;
// 		bureaucrat.signForm(form);
// 		bureaucrat.setGrade(10); // Set grade to allow execution
// 		bureaucrat.signForm(form);
// 		std::cout << form.isSigned() << std::endl; // Check if form is signed
// 		std::cout << form << std::endl;
// 		std::cout << "Executing form..." << std::endl;
// 		form.execute(bureaucrat);
// 		bureaucrat.setGrade(4);
// 		std::cout << form << std::endl;
// 		form.execute(bureaucrat);
// //		std::cout << "Presidential pardon executed successfully." << std::endl;
// 	} catch (std::exception &e) {
// 		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
// 	}

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

	// Clean up dynamically allocated forms
	delete form1;
	delete form2;
	delete form3;
	delete form4;

	return 0;
}

