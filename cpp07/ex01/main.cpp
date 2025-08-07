#include "iter.hpp"
#include "utils.hpp"

#include <iostream>
#include <string>

template <typename T>
void printElement(T& element) {
	std::cout << element << " ";
}

void incrementElement(int& element) {
	element++;
}

void incrementElement(std::string& element) {
	element += "!";
}

void incrementElement(char & element) {
	if (std::islower(element))
		element = std::toupper(element);
}



int main() {
	printTitle("Iter Template Function Test");


	int arr[] = { 0, 1, 2, 3, 4 };
	std::cout << "Original : ";
	::iter(arr, 5, printElement);
	std::cout << std::endl;
	::iter(arr, 5, incrementElement);
	std::cout << "Increment: ";
	::iter(arr, 5, printElement);
	std::cout << std::endl;

	std::cout << "Const array: ";
	const int constArr[] = { 5, 6, 7, 8, 9 };
	::iter(constArr, 5, printElement);
//	::iter(constArr, 5, incrementElement);

	std::cout << std::endl;

	printTitle("More Tests with Different Types");
	std::string strArr[] = { "42", "Vienna", "School", "!" };
	std::cout << "Original Strings: ";
	::iter(strArr, 4, printElement);

	std::cout << std::endl;
	::iter(strArr, 4, incrementElement);
	::iter(strArr, 4, printElement);
	std::cout << std::endl;

	char charArr[] = { 'a', 'b', 'c', 'd' };
	std::cout << "Original Characters: ";
	::iter(charArr, 4, printElement);
	std::cout << std::endl;
	::iter(charArr, 4, incrementElement);
	std::cout << "Incremented (Uppercase) :))) Characters: ";
	::iter(charArr, 4, printElement);
	std::cout << std::endl;

	int *a = new int();
	std::string *b = new std::string();
	std::cout << "Dynamic int: " << *a << std::endl;
	std::cout << "Dynamic string: " << *b << std::endl;
	delete a;
	delete b;
	return 0;
}
