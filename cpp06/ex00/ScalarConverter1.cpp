#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <string>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other; // Prevent unused parameter warning
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other; // Prevent unused parameter warning
	return *this;
}

bool isChar(const std::string &literal) {
	return (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]));
}

bool isInt(const std::string &literal) {
	if (literal.empty() || (literal.length() == 1 && !isdigit(literal[0]))) {
//		std::cout << "Int: Not a valid integer literal." << std::endl;
		return false;
	}
	if (!isdigit(literal[0]) && (!(literal[0] == '-' || literal[0] == '+'))) {
//		std::cout << "Int: Not a valid integer literal." << std::endl;
		return false;
	}
	for (size_t i = 1; i < literal.length(); ++i) {
		if (!isdigit(literal[i]) && !(literal[i] == '.') 
		&& !(i == literal.length() - 1 && (literal[i] == 'f' || literal[i] == 'F'))) {
//			std::cout << "Int: Not a valid integer." << std::endl;
			return false;
		}
	}
	return true;
}

void convertToInt(const std::string &literal) {
	if (!isInt(literal)) {
		return;
	}
	if (literal.empty() || (literal.length() == 1 && !isdigit(literal[0]))) {
		std::cout << "Int: Not a valid integer literal." << std::endl;
		return;
	}
	if (literal == "nan" || literal == "inf" || literal == "-inf") {
		std::cout << "Int: Not a valid integer literal." << std::endl;
		return;
	}
	long i = std::atol(literal.c_str());
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max()) {
		std::cout << "Int: Out of range." << std::endl;
		return;
	}
	std::cout << "Int: " << i << std::endl;

}