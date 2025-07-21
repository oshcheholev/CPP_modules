#include "AForm.hpp"

#include <iostream>

AForm::AForm()
	: _name("Default"), _signGrade(150), 
	_executeGrade(150), _isSigned(false) {
	std::cout << GREEN << "Default AForm constructor called for " 
			  << _name << " with sign grade " << _signGrade 
			  << " and execute grade " << _executeGrade << RESET << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _signGrade(signGrade), 
	_executeGrade(executeGrade), _isSigned(false) {
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << GREEN << "AForm constructor called for " << _name 
			  << " with sign grade " << _signGrade 
			  << " and execute grade " << _executeGrade << RESET << std::endl;
}
AForm::AForm(const AForm& other)
	: _name(other._name), _signGrade(other._signGrade), 
	  _executeGrade(other._executeGrade), _isSigned(other._isSigned) {
	std::cout << GREEN << "AForm copy constructor called for " << _name << RESET << std::endl;
}
AForm::~AForm() {
	std::cout << YELLOW << "AForm destructor called for " << _name << RESET <<
	 std::endl;
}
AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
		std::cout << GREEN << "AForm assignment operator called for "
				  << _name << " with sign grade " << _signGrade
				  << " and execute grade " << _executeGrade << RESET << std::endl;
	}
	return *this;
}
const std::string& AForm::getName() const {
	return _name;
}
int AForm::getSignGrade() const {
	return _signGrade;
}
int AForm::getExecuteGrade() const {
	return _executeGrade;
}
bool AForm::isSigned() const {
	return _isSigned;
}
void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooHighException();
	_isSigned = true;
	std::cout << BLUE << "AForm " << _name 
			  << " has been signed by " << bureaucrat.getName() 
			  << " with grade " << bureaucrat.getGrade() << RESET << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm grade is too high!";
}
const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << MAGENTA << "AForm: " << form.getName() 
	   << ", Sign Grade: " << form.getSignGrade() 
	   << ", Execute Grade: " << form.getExecuteGrade() 
	   << ", Signed: " << (form.isSigned() ? "Yes" : "No") 
	   << RESET;
	return os;
}
