#include "PMergeMe.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <positive integers>" << std::endl;
		return 1;
	}

	PMergeMe pMergeMe;

	try
	{
		pMergeMe.parseInput(argc, argv);
		pMergeMe.sortAndMeasure();
		pMergeMe.printResults();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}