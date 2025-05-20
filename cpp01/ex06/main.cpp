#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "To complain you should add complain level: " 
		<< std::endl << argv[0] << " <level>" << std::endl;
		std::cout << "Available levels: " << LEVELS_STR << std::endl;
		std::cout << "Example: " << argv[0] << " DEBUG" << std::endl;
		std::cout << "Example: " << argv[0] << " INFO" << std::endl;
		std::cout << "Example: " << argv[0] << " WARNING" << std::endl;
		std::cout << "Example: " << argv[0] << " ERROR" 
		<< std::endl << std::endl;

		return 1;
	}
	Harl harl;
	harl.complain(argv[1]);
	return 0;
}