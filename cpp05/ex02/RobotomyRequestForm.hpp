#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	const std::string& getTarget() const;
	void execute(const Bureaucrat& bureaucrat) const;
	class RobotomyFailureException : public std::exception {
	public:
		const char* what() const throw() {
			return "Robotomy request failed.";
		}
	};

};

#endif