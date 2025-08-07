#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ostream>

Intern::Intern() {
	std::cout << GREEN << "Intern default constructor called." << RESET << std::endl;
}
Intern::Intern(const Intern& other) {
	(void)other;
	std::cout << GREEN << "Intern copy constructor called." << RESET << std::endl;
}
Intern::~Intern() {
	std::cout << YELLOW << "Intern destructor called." << RESET << std::endl;
}
Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {
		std::cout << GREEN << "Intern assignment operator called." << RESET << std::endl;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Intern& intern) {
	(void)intern; // Mark parameter as used to avoid warning
	os << "Intern";
	
	return os;
}

std::string nameToLower(const std::string& name) {
	std::string lowerName = name;
	for (size_t i = 0; i < lowerName.length(); ++i) {
		lowerName[i] = tolower(lowerName[i]);
	}
	return lowerName;
}


AForm* createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}
AForm* createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}
AForm* createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	AForm* form = NULL;
	std::string lowerFormName = nameToLower(formName);

const std::string formTypes[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
AForm* (*functionPointers[3])(const std::string&) = {
		createShrubberyCreationForm,
		createRobotomyRequestForm,
		createPresidentialPardonForm
	};
	
	for (int i = 0; i < 3; ++i) {
		if (lowerFormName == formTypes[i]) {
			form = functionPointers[i](target);
			break;
		}
	}

	if (!form) {
		std::cerr << RED << "Intern could not create form: " << formName << RESET << std::endl;
		return NULL;
	}

	std::cout << GREEN << "Intern creates " << *form << RESET << std::endl;
	return form;
}

