#include "utils.cpp"
#include "Array.tpp"

#include <iostream>
#include <string>



int main() {
	printTitle("Int Array Test");
	Array<int> intArray(5);
	for (size_t i = 0; i < intArray.size(); ++i) {
		intArray[i] = i * 2;
	}
	for (size_t i = 0; i < intArray.size(); ++i) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	printTitle("String Array Test");
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";
	for (size_t i = 0; i < strArray.size(); ++i) {
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;

	printTitle("Out of Bounds Test");
	try {
		std::cout << strArray[3] << std::endl; // This should throw
	} catch (const std::out_of_range& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	printTitle("Empty Array Test");
	Array<double> emptyArray;
	std::cout << "Size of empty array: " << emptyArray.size() << std::endl;
	try {
		std::cout << emptyArray[0] << std::endl; // This should throw
	} catch (const std::out_of_range& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	return 0;
}
