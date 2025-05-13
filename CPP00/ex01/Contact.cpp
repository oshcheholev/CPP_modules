#include "Contact.hpp"
#include <iostream>

Contact::Contact() :
	_firstName(""),
	_lastName(""),
	_nickname(""),
	_phoneNumber(""),
	_darkestSecret("")
{
	// Constructor
}

Contact::~Contact()
{
	// Destructor
}
void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}
void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}
void	Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}
void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}
void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}
std::string	Contact::getFirstName() const
{
	return this->_firstName;
}
std::string	Contact::getLastName() const
{
	return this->_lastName;
}
std::string	Contact::getNickname() const
{
	return this->_nickname;
}
std::string	Contact::getPhoneNumber() const
{
	return this->_phoneNumber;
}
std::string	Contact::getDarkestSecret() const
{
	return this->_darkestSecret;
}

bool	Contact::isEmpty() const
{
	return this->_firstName.empty() && this->_lastName.empty() && this->_nickname.empty()
		&& this->_phoneNumber.empty() && this->_darkestSecret.empty();
}

void	Contact::printContact() const
{
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}

void	Contact::printContactInfo(std::string str) const
{
	if (str == "firstName")
		std::cout << "First Name: " << this->_firstName << std::endl;
	else if (str == "lastName")
		std::cout << "Last Name: " << this->_lastName << std::endl;
	else if (str == "nickname")
		std::cout << "Nickname: " << this->_nickname << std::endl;
	else if (str == "phoneNumber")
		std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	else if (str == "darkestSecret")
		std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}
// Contact.cpp