#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>

#define GREEN "\033[32m"
#define YELLOW "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

class Bureaucrat {
private:
	std::string _name;
	int _grade;
public:
	
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& other);
	const std::string& getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void setGrade(int grade);
	void setName(const std::string& name);
	void signForm(class Form& form) const;
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif