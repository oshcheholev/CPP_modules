#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	const std::string& getTarget() const;
	void execute(const Bureaucrat& bureaucrat) const;
	class PresidentialPardonException : public std::exception {
	public:
		const char* what() const throw() {
			return "Presidential pardon error.";
		}
	};
};

#endif