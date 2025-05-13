#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>

PhoneBook::PhoneBook() : _index(0), _count(0)
{
	// Constructor
}
PhoneBook::~PhoneBook()
{
	// Destructor
}

void PhoneBook::addContact()
{
	Contact contact;
	std::string input;

	// if (_count >= 8)
	// {
	// 	std::cout << "PhoneBook is full. Cannot add more contacts." << std::endl;
	// 	return;
	// }
	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	if (input.length() == 0)
	{
		std::cout << "First name cannot be empty." << std::endl;
		return;
	}
	if (input.length() > 20)
	{
		std::cout << "First name is too long. Please enter a name with less than 20 characters." << std::endl;
		return;
	}
	if (input[0] == ' ')
	{
		std::cout << "First name cannot start with a space." << std::endl;
		return;
	}
	contact.setFirstName(input);
	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	if (input.length() == 0)
	{
		std::cout << "Last name cannot be empty." << std::endl;
		return;
	}
	if (input.length() > 20)
	{
		std::cout << "Last name is too long. Please enter a name with less than 20 characters." << std::endl;
		return;
	}
	if (input[0] == ' ')
	{
		std::cout << "Last name cannot start with a space." << std::endl;
		return;
	}
	contact.setLastName(input);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	if (input.length() == 0)
	{
		std::cout << "Nickname cannot be empty." << std::endl;
		return;
	}
	if (input.length() > 20)
	{
		std::cout << "Nickname is too long. Please enter a name with less than 20 characters." << std::endl;
		return;
	}
	if (input[0] == ' ')
	{
		std::cout << "Nickname cannot start with a space." << std::endl;
		return;
	}
	contact.setNickname(input);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	if (input.length() > 15)
	{
		std::cout << "Phone number is too long. Please enter a number with less than 15 digits." << std::endl;
		return;
	}
	if (input.length() == 0)
	{
		std::cout << "Phone number cannot be empty." << std::endl;
		return;
	}
	if (input.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Phone number can only contain digits." << std::endl;
		return;
	}
	contact.setPhoneNumber(input);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	if (input.length() == 0)
	{
		std::cout << "Darkest secret cannot be empty." << std::endl;
		return;
	}
	if (input.length() > 20)
	{
		std::cout << "Darkest secret is too long. Please enter a secret with less than 50 characters." << std::endl;
		return;
	}
	contact.setDarkestSecret(input);

	_contacts[_index] = contact;
	if (_count < 8)
		_count++;
	_index = (_index + 1) % 8;
	std::cout << std::endl;
	std::cout << "Contact added successfully!" << std::endl;
	std::cout << std::endl;

}

std::string PhoneBook::formatString(const std::string &str) const
{
if (str.length() > 10)
	return str.substr(0, 9) + ".";
return str;
}



void PhoneBook::searchContact() const
{
	std::cout << "+-------------------------------------------+" << std::endl;
	std::cout << "|" 
			<< std::setw(10) << "Index " << "|" 
			<< std::setw(10) << "First Name" << "|" 
			<< std::setw(10) << "Last Name" << "|" 
			<< std::setw(10) << "Nickname  |" << std::endl;
	std::cout << "+-------------------------------------------+" << std::endl;
//			  std::cout << std::string(42, '-') << std::endl;

	for (int i = 0; i < _count; i++)
	{
		std::cout << "|" 
			<< std::setw(10) << i + 1 << "|"
			<< std::setw(10) << formatString(_contacts[i].getFirstName()) << "|"
			<< std::setw(10) << formatString(_contacts[i].getLastName()) << "|"
			<< std::setw(10) << formatString(_contacts[i].getNickname()) << "|" << std::endl;
		std::cout << "+-------------------------------------------+" << std::endl;
	}

}

void PhoneBook::printContactInfo() const
{
	std::string input;
	int i;

	if (_count == 0)
	{
		std::cout << "No contacts available." << std::endl;
		std::cout << "Please add a contact first." << std::endl;
		std::cout << std::endl;
		return;
	}
	searchContact();
	std::cout << "Enter the index of the contact you want to view (1-" << _count << "): ";
	std::getline(std::cin, input);
	try
	{
		std::stringstream ss(input);
		if (!(ss >> i)) {
			std::cout << "Invalid input. Please enter a number1." << std::endl;
			return;
		}
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Invalid input. Please enter a number." << std::endl;
		return;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Input out of range." << std::endl;
		return;
	}
	if (input.length() == 0)
	{
		std::cout << "Index cannot be empty." << std::endl;
		return;
	}
	if (std::cin.eof())
	{
		std::cout << "Exiting PhoneBook." << std::endl;
		return;
	}

	if (i < 0 || i > _count)
	{
		std::cout << "Invalid index: " << i << std::endl;
		std::cout << "Please enter a number between 1 and " << _count << "." << std::endl;
		std::cout << std::endl;
		return;
	}
	std::cout << "Contact " << i << ":" << std::endl;
	_contacts[i - 1].printContact();
}

void PhoneBook::exit() const
{
	std::cout << std::endl << "Exiting PhoneBook. Goodbye!" << std::endl;
}


// PhoneBook.cpp