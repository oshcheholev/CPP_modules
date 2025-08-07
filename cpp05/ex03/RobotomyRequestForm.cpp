#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("Default") {
	std::cout << GREEN << "Default RobotomyRequestForm constructor called for " 
			  << _target << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {
	if (target.empty())
		throw RobotomyFailureException();
	std::cout << GREEN << "RobotomyRequestForm constructor called for " 
			  << _target << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {
	std::cout << GREEN << "RobotomyRequestForm copy constructor called for " 
			  << _target << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << YELLOW << "RobotomyRequestForm destructor called for " 
			  << _target << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
		std::cout << GREEN << "RobotomyRequestForm assignment operator called for " 
				  << _target << RESET << std::endl;
	}
	return *this;
}

const std::string& RobotomyRequestForm::getTarget() const {
	return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const {
	if (!isSigned())
		std::cerr << RED << "AForm is not signed!" << RESET << std::endl;
	else if (bureaucrat.getGrade() > getExecuteGrade())
		std::cerr << RED << "Bureaucrat grade too low to execute form." << RESET << std::endl;
	else {
		std::cout << '\a' << "Bzzzzzz... Robotomy request for " << _target << " is being processed." << std::endl;
        for (int i = 0; i < 3; ++i) {
            usleep(500000); // 0.5 second delay (Linux/macOS)
            std::cout << "BZZZ... " << std::endl;
            std::cout.flush();
        }
		srand(time(0));
		if (rand() % 2) {
			std::cout << GREEN << _target << " has been robotomized successfully!" << RESET << std::endl;
		} else {
			std::cout << RED << "Robotomy request for " << _target << " failed." << RESET << std::endl;
		}
		std::cout << BLUE << "Robotomy request for " << _target << " executed by " 
				<< bureaucrat.getName() << " with grade " 
				<< bureaucrat.getGrade() << RESET << std::endl;
	}
}