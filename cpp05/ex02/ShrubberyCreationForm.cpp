#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("Default") {
	std::cout << GREEN << "Default ShrubberyCreationForm constructor called for " 
			  << _target << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	if (target.empty())
		throw FileCreationException();
	std::cout << GREEN << "ShrubberyCreationForm constructor called for " 
			  << _target << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {
	std::cout << GREEN << "ShrubberyCreationForm copy constructor called for " 
			  << _target << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << YELLOW << "ShrubberyCreationForm destructor called for " 
			  << _target << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
		std::cout << GREEN << "ShrubberyCreationForm assignment operator called for " 
				  << _target << RESET << std::endl;
	}
	return *this;
}

const std::string& ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {
	if (!isSigned())
		throw AForm::GradeTooLowException();
	if (bureaucrat.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw FileCreationException();

	file << "       _~_~_~_\n";
	file << "    /~~       ~~\\\n";
	file << "   /~~         ~~\\\n";
	file << "  |~~           ~~|\n";
	file << "   \\~~         ~~/\n";
	file << "    \\~~_______~~/\n";
	file << "         |_|\n";
	file << "         |_|\n";
	file << "         |_|\n";
	file << "         |_|\n";
	file << "      /~~   ~~\\\n";
	file.close();

	std::cout << BLUE << "Shrubbery created at " << _target 
			  << "_shrubbery by " << bureaucrat.getName() 
			  << " with grade " << bureaucrat.getGrade() << RESET << std::endl;
}