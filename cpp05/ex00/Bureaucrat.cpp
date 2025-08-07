#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade) 
{
	std::cout << GREEN << "Bureaucrat constructor called for "
	<< name << " with grade " << grade << RESET << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_name = name;
	this->_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	this->_name = other._name;
	this->_grade = other._grade;
	std::cout << GREEN << "Bureaucrat copy constructor called for " 
	<<  this->_name << RESET << std::endl;
}
Bureaucrat::~Bureaucrat() {
	std::cout << YELLOW << "Bureaucrat destructor called for " 
	<< RESET << _name << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_name = other._name;
		_grade = other._grade;
		std::cout << GREEN << "Bureaucrat assignment operator called for "
		<< _name << " with grade " << _grade << RESET << std::endl;
	}
	return *this;
}
const std::string& Bureaucrat::getName() const {
	return _name;
}
int Bureaucrat::getGrade() const {
	return _grade;
}
void Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << BLUE << "Bureaucrat " << _name << " incremented to grade " 
	<< _grade << RESET << std::endl;
	}
void Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
	std::cout << BLUE << "Bureaucrat " << _name << " decremented to grade "
	<< _grade << RESET << std::endl;
}
void Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << BLUE << "Bureaucrat " << _name << " grade set to " 
	<< _grade << RESET << std::endl;
}
void Bureaucrat::setName(const std::string& name) {
	_name = name;
	std::cout << GREEN << "Bureaucrat name set to " 
	<< _name << RESET << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade is too high!";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
os << GREEN << bureaucrat.getName() << RESET 
   << ", bureaucrat grade " << MAGENTA << bureaucrat.getGrade() 
   << RESET << std::endl;
	return os;
}