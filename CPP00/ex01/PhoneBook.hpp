#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_index;
	int		_count;

public:
	PhoneBook();
	~PhoneBook();

	void	addContact();
	void	searchContact() const;
	void	printContactInfo() const;
	void	exit() const;

	std::string formatString(const std::string &str) const;
};

#endif
// PhoneBook.hpp
