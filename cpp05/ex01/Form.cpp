#include "Form.hpp"

#include <iostream>

Form::Form()
	: _name("Default"), _signGrade(150), 
	_executeGrade(150), _isSigned(false) {
	std::cout << GREEN << "Default Form constructor called for " 
			  << _name << " with sign grade " << _signGrade 
			  << " and execute grade " << _executeGrade << RESET << std::endl;
}

Form::Form(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _signGrade(signGrade), 
	_executeGrade(executeGrade), _isSigned(false) {
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << GREEN << "Form constructor called for " << _name 
			  << " with sign grade " << _signGrade 
			  << " and execute grade " << _executeGrade << RESET << std::endl;
}
Form::Form(const Form& other)
	: _name(other._name), _signGrade(other._signGrade), 
	  _executeGrade(other._executeGrade), _isSigned(other._isSigned) {
	std::cout << GREEN << "Form copy constructor called for " << _name << RESET << std::endl;
}
Form::~Form() {
	std::cout << YELLOW << "Form destructor called for " << _name << RESET <<
	 std::endl;
}
Form& Form::operator=(const Form& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
		std::cout << GREEN << "Form assignment operator called for "
				  << _name << " with sign grade " << _signGrade
				  << " and execute grade " << _executeGrade << RESET << std::endl;
	}
	return *this;
}
const std::string& Form::getName() const {
	return _name;
}
int Form::getSignGrade() const {
	return _signGrade;
}
int Form::getExecuteGrade() const {
	return _executeGrade;
}
bool Form::isSigned() const {
	return _isSigned;
}
void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooHighException();
	_isSigned = true;
	std::cout << BLUE << "Form " << _name 
			  << " has been signed by " << bureaucrat.getName() 
			  << " with grade " << bureaucrat.getGrade() << RESET << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}
const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << MAGENTA << "Form: " << form.getName() 
	   << ", Sign Grade: " << form.getSignGrade() 
	   << ", Execute Grade: " << form.getExecuteGrade() 
	   << ", Signed: " << (form.isSigned() ? "Yes" : "No") 
	   << RESET;
	return os;
}
