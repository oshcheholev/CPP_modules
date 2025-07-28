#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

class Form {
private:
	const std::string _name;
	const int _signGrade;
	const int _executeGrade;
	bool _isSigned;
public:
	Form();
	Form(const std::string& name, int signGrade, int executeGrade);
	Form(const Form& other);
	~Form();
	Form& operator=(const Form& other);
	const std::string& getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	bool isSigned() const;
	void beSigned(const Bureaucrat& bureaucrat) ;


	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif