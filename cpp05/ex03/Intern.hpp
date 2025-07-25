#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class Intern {
public:
	Intern();
	Intern(const Intern& other);
	~Intern();

	Intern& operator=(const Intern& other);

	AForm* makeForm(const std::string& formName, const std::string& target);
};
std::ostream& operator<<(std::ostream& os, const Intern& intern);

#endif // INTERN_HPP