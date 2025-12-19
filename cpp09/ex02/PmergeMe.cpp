#include "PMergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <climits>

static bool checkInput(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}
template <typename T>
static void printData (const T& data)
{
	std::cout << data.size() << " elements: ";
	for (typename T::const_iterator it = data.begin(); it != data.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// static void insertLeftover(std::vector<int>& sortedData, int value)
// {
// 	// Insert value into sortedData maintaining sorted order
// 	sortedData.push_back(value);
// 	size_t i = sortedData.size() - 1;
// 	while (i > 0 && sortedData[i - 1] > sortedData[i])
// 	{
// 		std::swap(sortedData[i - 1], sortedData[i]);
// 		--i;
// 	}
// }
template <typename Container>
static void binaryInsert(Container& v, const typename Container::value_type& value)
{
	typename Container::iterator pos =
		std::lower_bound(v.begin(), v.end(), value);
	v.insert(pos, value);
}

template <typename Container>
static Container mergeInsertSort(Container& input)
{
	if (input.size() <= 1)
		return input;

	typedef typename Container::value_type T;
	std::vector< std::pair<T, T> > pairs;
	Container bigs;
	std::vector<T> smalls;

	bool hasLeftover = false;
	T leftover = T();

	// 1️⃣ Make pairs
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		T a = input[i];
		T b = input[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	if (input.size() % 2 != 0)
	{
		leftover = input.back();
		hasLeftover = true;
	}

	// 2️⃣ Split into smalls and bigs
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		smalls.push_back(pairs[i].first);
		bigs.push_back(pairs[i].second);
	}

	// 3️⃣ Sort bigs
	std::sort(bigs.begin(), bigs.end());

	// 4️⃣ Insert smalls into bigs
	for (size_t i = 0; i < smalls.size(); ++i)
	{
		binaryInsert(bigs, smalls[i]);
	}

	// 5️⃣ Insert leftover
	if (hasLeftover)
	{
		binaryInsert(bigs, leftover);
	}

	return bigs;
}
// static std::vector<int> makeAndSortPairs(const std::vector<int>& data)
// {
// 	std::cout << "Before sorting: ";
// 	printVector(data);
// 	if (data.size() == 0)
// 		return std::vector<int>();
// 	std::vector< std::pair<int, int> > pairs;
// 	int leftover;
// 	bool hasLeftover = false;
// 	for (size_t i = 0; i + 1 < data.size(); i += 2)
// 	{
// 		int a = data[i];
// 		int b = data[i + 1];
// 		if (a > b)
// 			std::swap(a, b);
// 		pairs.push_back(std::make_pair(a, b));
// 	}
// 	if (data.size() % 2 != 0)
// 	{
// 		leftover = data.back();
// 		hasLeftover = true;
// //		pairs.push_back(std::make_pair(data.back(), INT_MAX));
// 	}
// 	for (size_t i = 0; i < pairs.size(); ++i)
// 	{
// //		std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
// 		// if (hasLeftover && i == 0)
// 		// {
// 		// 	std::cout << "(" << leftover << ", " << "X) ";
// 		// }
// 		if (pairs[i].first > pairs[i].second)
// 		{
// 			std::swap(pairs[i].first, pairs[i].second);
// 		}

// 	}
	
// 	// std::cout << "After sorting pairs: " << std::endl;
// 	std::vector<int> lowerPart;
// 	std::vector<int> upperPart;
// 	for (size_t i = 0; i < pairs.size(); ++i)
// 	{
// 		lowerPart.push_back(pairs[i].first);
// 	}
// 	for (size_t i = 0; i < pairs.size(); ++i)
// 	{
// 		upperPart.push_back(pairs[i].second);
// 	}
// 	if (hasLeftover)
// 	{
// 		insertLeftover(upperPart, leftover);
// 		hasLeftover = false;
// 	}
// 	if (upperPart.size() > 1)
// 	{
// 		upperPart = makeAndSortPairs(upperPart);
// 	}
// 	// printVector(lowerPart);
// 	// printVector(upperPart);

// 	//!!!!!!!!!!!!!!!!!!!!!!!!!!
// 	// std::sort(upperPart.begin(), upperPart.end());
// 	//!!!!!!!!!!!!!!!!!!!!!!!!!!


// 	std::vector<int> sortedData;
// 	for (size_t i = 0; i < lowerPart.size(); ++i)
// 	{
// 		sortedData.push_back(lowerPart[i]);
// 	}
// 	for (size_t i = 0; i < upperPart.size(); ++i)
// 	{
// 		// Insert upperPart[i] into sortedData
// 		sortedData.push_back(upperPart[i]);
// 	}
// 	// if (hasLeftover)
// 	// {
// 	// 	sortedData.push_back(leftover);
// 	// }
// 	printVector(sortedData);
// 	return sortedData;
// }

PMergeMe::PMergeMe()
	: vectorSortTime(0), dequeSortTime(0)
{
}

PMergeMe::PMergeMe(const PMergeMe& other)
	: Vector(other.Vector),
	  Deque(other.Deque),
	  vectorSortTime(other.vectorSortTime),
	  dequeSortTime(other.dequeSortTime)
{}

PMergeMe& PMergeMe::operator=(const PMergeMe& other)
{
	if (this != &other)
	{
		Vector = other.Vector;
		Deque = other.Deque;
		vectorSortTime = other.vectorSortTime;
		dequeSortTime = other.dequeSortTime;
	}
	return *this;
}
PMergeMe::~PMergeMe()
{
}

void PMergeMe::parseInput(int argc, char** argv)
{

	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		if (!checkInput(arg))
		{
			throw std::invalid_argument("Error: Invalid input. Only positive integers are allowed.");
		}
		int value = std::atoi(arg.c_str());
		Vector.push_back(value);
		Deque.push_back(value);
	}
	printData(Vector);
	printData(Deque);
}

void PMergeMe::sortAndMeasure()
{
	clock_t start, end;

	// Sort using vector
	start = clock();
	std::cout << "Vector Before sorting: " << std::endl;
	printData(Vector);
	Vector = ::mergeInsertSort(Vector);
	// makeAndSortPairs(Vector);
	std::cout << "Vector After sorting: " << std::endl;
	printData(Vector);
	end = clock();
	vectorSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // microseconds

	// Sort using deque
	start = clock();
	std::cout << "Deque Before sorting: " << std::endl;
	printData(Deque);
	Deque = ::mergeInsertSort(Deque);
	end = clock();
	std::cout << "Deque After sorting: " << std::endl;
	printData(Deque);
	
	dequeSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // microseconds

}

void PMergeMe::printResults() const
{
	std::cout << "Time to process a range of " << Vector.size()
			  << " elements with std::vector : " << vectorSortTime << " us" << std::endl;
	std::cout << "Time to process a range of " << Deque.size()
			  << " elements with std::deque : " << dequeSortTime << " us" << std::endl;
}
