#include "iter.hpp"
#include "utils.cpp"

#include <iostream>
#include <string>

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}
template <typename T>
void printElement(T &element) {
	std::cout << element << " ";
}

template <typename T>
void incrementElement(T& element) {
	element++;
}

template <>
void incrementElement<std::string>(std::string& element) {
	element += "!";
}

template <>
void incrementElement<char>(char & element) {
	if (std::islower(element))
		element = std::toupper(element);
}

template <>
void incrementElement<double>(double& element) {
	element += 1.0;
}

int main() {
	printTitle("Iter Template Function Test");


	int arr[] = { 0, 1, 2, 3, 4 };
	std::cout << "Original : ";
	iter(arr, 5, printElement<int>);
	std::cout << std::endl;
	iter(arr, 5, incrementElement<int>);
	std::cout << "Increment: ";
	iter(arr, 5, printElement<int>);
	std::cout << std::endl;

	std::cout << "Const array: ";
	const int constArr[] = { 5, 6, 7, 8, 9 };
	iter(constArr, 5, printElement<const int>);
	// iter<const int>(constArr, 5, incrementElement);
	//Can't increment const array elements

	std::cout << std::endl;

	printTitle("More Tests with Different Types");

	double doubleArr[] = { 1.11, 2.22, 3.33 };
	std::cout << "Original doubles: ";
	iter(doubleArr, 3, printElement<double>);
	std::cout << std::endl;
	iter(doubleArr, 3, incrementElement<double>);
	std::cout << "Incremented doubles: ";
	iter(doubleArr, 3, printElement<double>);
	std::cout << std::endl;
	std::cout << std::endl;

	std::string strArr[] = { "42", "Vienna", "School", "!" };
	std::cout << "Original Strings: ";
	iter(strArr, 4, printElement<std::string>);

	std::cout << std::endl;
	iter(strArr, 4, incrementElement<std::string>);
	iter(strArr, 4, printElement<std::string>);
	std::cout << std::endl;
	std::cout << std::endl;

	char charArr[] = { 'a', 'b', 'c', 'd' };
	std::cout << "Original Characters: ";
	iter(charArr, 4, printElement<char>);
	std::cout << std::endl;
	iter(charArr, 4, incrementElement<char>);
	std::cout << "Incremented (Uppercase) :))) Characters: ";
	iter(charArr, 4, printElement<char>);
	std::cout << std::endl;
	std::cout << std::endl;

  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  int len = 5;

  iter( tab, len, print<int> );
  iter( tab2, len, print<Awesome> );
  //iter( tab, len, add<int> );
  iter( tab, len, incrementElement<int> );
  // iter( tab2, len, add<Awesome> );
  std::cout << "After add function:" << std::endl;
  iter( tab, len, print<int> );
  iter( tab2, len, print<Awesome> );


	return 0;
}
