#ifndef PMERGEME_HPP
#define PMERGEME_HPP




#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <ctime>

class PMergeMe
{
public:
	PMergeMe();
	PMergeMe(const PMergeMe& other);
	PMergeMe& operator=(const PMergeMe& other);
	~PMergeMe();

	void parseInput(int argc, char** argv);
	void sortAndMeasure();
	void printResults() const;

private:
	std::vector<int> Vector;
	std::deque<int> Deque;
	double vectorSortTime;
	double dequeSortTime;
	// Sorting helpers implemented as free templates in the cpp file.
};

#endif // PMERGEME_HPP