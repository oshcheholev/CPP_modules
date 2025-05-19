#include <iostream>
#include <string>


int main() {
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "The address of the string is: " << &brain << std::endl;
	std::cout << "The address of the stringPTR is: " << stringPTR << std::endl;
	std::cout << "The address of the stringREF is: " << &stringREF << std::endl;

	std::cout << "The value of the string is: " << brain << std::endl;
	std::cout << "The value of the stringPTR is: " << *stringPTR << std::endl;
	std::cout << "The value of the stringREF is: " << stringREF << std::endl;

	return 0;
}

