#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	const std::string& getTarget() const;
	void execute(const Bureaucrat& bureaucrat) const;
	class FileCreationException : public std::exception {
	public:
		const char* what() const throw() {
			return "File creation error.";
		}
	};
};