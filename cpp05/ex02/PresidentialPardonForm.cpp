#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("Default") {
	std::cout << GREEN << "Default PresidentialPardonForm constructor called for " 
			  << _target << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {
	if (target.empty())
		throw PresidentialPardonException();
	std::cout << GREEN << "PresidentialPardonForm constructor called for " 
			  << _target << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target) {
	std::cout << GREEN << "PresidentialPardonForm copy constructor called for " 
			  << _target << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << YELLOW << "PresidentialPardonForm destructor called for " 
			  << _target << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
		std::cout << GREEN << "PresidentialPardonForm assignment operator called for " 
				  << _target << RESET << std::endl;
	}
	return *this;
}

const std::string& PresidentialPardonForm::getTarget() const {
	return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const {
	if (!isSigned())
		std::cerr << RED << "AForm is not signed!" << RESET << std::endl;
	else if (bureaucrat.getGrade() > getExecuteGrade())
		std::cerr << RED << "Bureaucrat grade too low to execute form." << RESET << std::endl;
	else {
		std::cout << "Presidential pardon for " << _target << " is being processed." << std::endl;
		std::cout << GREEN << _target << " has been pardoned by Zaphod Beeblebrox!" << RESET << std::endl;
		std::cout << BLUE << "Presidential pardon for " << _target << " executed by " 
				<< bureaucrat.getName() << " with grade "
				<< bureaucrat.getGrade() << RESET << std::endl;
		if (bureaucrat.getGrade() < 1)
			throw PresidentialPardonException();
		std::cout << GREEN << "Presidential pardon executed successfully." << RESET << std::endl;
	}
}