#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"


// made abstract class
class AForm {
private:
	const std::string _name;
	const int _signGrade;
	const int _executeGrade;
	bool _isSigned;
public:
	AForm();
	AForm(const std::string& name, int signGrade, int executeGrade);
	AForm(const AForm& other);
	~AForm();
	AForm& operator=(const AForm& other);
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

	// virtual execute, implement in derived classes
	virtual void execute(const Bureaucrat& bureaucrat) const = 0;


};
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif