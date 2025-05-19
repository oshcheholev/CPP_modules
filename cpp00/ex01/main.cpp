#include "PhoneBook.hpp"
#include <iostream>

void DisplayWelcomeMessage()
{
	std::cout << "+----------------------------------------------+" << std::endl;
	std::cout << "|         Welcome to Awesome PhoneBook!        |" << std::endl;
	std::cout << "+----------------------------------------------+" << std::endl;
	std::cout << "| You can add, search, and exit the PhoneBook. |" << std::endl;
	std::cout << "| Please enter a command: ADD, SEARCH, or EXIT.|" << std::endl;
	std::cout << "+----------------------------------------------+" << std::endl;
	std::cout << std::endl;
}


int main()
{
	PhoneBook phoneBook;
	std::string command;

	DisplayWelcomeMessage();
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << "Exiting PhoneBook." << std::endl;
			break;
		}
		else if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.printContactInfo();
		else if (command == "EXIT")
		{
			phoneBook.exit();
			break;
		}
		else
			std::cout << "Invalid command. Please try again." << std::endl;
		command.clear();
	}
	return 0;
}