#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "To complain speciffically you should add complain level: " 
		<< std::endl << argv[0] << " <level>" << std::endl;
		std::cout << "Available levels: " << LEVELS_STR << std::endl;
		std::cout << "Example: " << argv[0] << " DEBUG" << std::endl;
		std::cout << "Example: " << argv[0] << " INFO" << std::endl;
		std::cout << "Example: " << argv[0] << " WARNING" << std::endl;
		std::cout << "Example: " << argv[0] << " ERROR" 
		<< std::endl << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Complaining automatically " << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		Harl harl;
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		
		return 0;
	}
	Harl harl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Complaining with argument: " << argv[1] << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	harl.complain(argv[1]);
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Complaining automatically " << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	return 0;
}