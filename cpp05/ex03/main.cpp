
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


	printTitle("Test from Subject");
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	if (rrf) {
		std::cout << *rrf << std::endl;
		delete rrf; // Clean up the dynamically allocated form
	} else {
		std::cout << "Form creation failed." << std::endl;
	}


	printTitle("Intern Form Creation test");
	Intern intern;
	std::cout << intern << std::endl;

	AForm* form1 = intern.makeForm("shrubbery creation", "Home");
	AForm* form2 = intern.makeForm("robotomy request", "Bender");
	AForm* form3 = intern.makeForm("Presidential Pardon", "Drucilla");
	
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

	printTitle("Form Signing Test ");
	try {
		Bureaucrat bureaucrat("Eduardo", 1);
		std::cout << bureaucrat << std::endl;

		std::cout << *form1 << std::endl;
		bureaucrat.signForm(*form1);
		std::cout << *form1 << std::endl;
		form1->execute(bureaucrat);
		bureaucrat.signForm(*form2);
		std::cout << *form2 << std::endl;
		form2->execute(bureaucrat);

		bureaucrat.signForm(*form3);
		std::cout << *form3 << std::endl;
		form3->execute(bureaucrat);

		if (form4) {
			std::cout << *form4 << std::endl;
			bureaucrat.signForm(*form4);
		} else {
			std::cout << RED << "Form4 not created." << RESET << std::endl;
		}
		if (form4) {
			form4->execute(bureaucrat);
		} else {
			std::cout << RED << "Form4 not created." << RESET << std::endl;
		}
	} catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	if (form1) {
		delete form1;
	}
	else {
		std::cout << RED << "Form1 not created." << RESET << std::endl;
	}
	if (form2) {
		delete form2;
	}
	else {
		std::cout << RED << "Form2 not created." << RESET << std::endl;
	}
	if (form3) {
		delete form3;
	}
	else {
		std::cout << RED << "Form3 not created." << RESET << std::endl;
	}
	if (form4) {
		delete form4;
	}
	else {
		std::cout << RED << "Form4 not created." << RESET << std::endl;
	}
	return 0;
}

