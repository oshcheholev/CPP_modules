
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

void convertToChar(const std::string &literal) {
	if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0])) {
		std::cout << "Character: " << literal << std::endl;
	}
	else {
		std::cout << "Character: impossible" << std::endl;
		return;
	}
}

bool isInt(const std::string &literal) {
	if (literal.empty() || (literal.length() == 1 && !isdigit(literal[0]))) {
		return false;
	}
	size_t i = 0;
	if (!isdigit(literal[i]) && (!(i == 0 && (literal[i] == '-' || literal[i] == '+')))) {
		return false;
	}
	i++;
	for (; i < literal.length(); ++i) {
		if (!isdigit(literal[i]) && !(literal[i] == '.') && !(i == literal.length() - 1 && (literal[i] == 'f' || literal[i] == 'F'))) {
			return false;
		}
	}
	return true;
}

void convertToInt(const std::string &literal) {
	if (!isInt(literal)) {
		std::cout << "Int: Not a valid integer literal." << std::endl;
		return;
	}
	// if (literal.empty() || (literal.length() == 1 && !isdigit(literal[0]))) {
	// 	std::cout << "Int: Not a valid integer literal." << std::endl;
	// 	return;
	// }
	// if (literal == "nan" || literal == "inf" || literal == "-inf") {
	// 	std::cout << "Int: Not a valid integer literal." << std::endl;
	// 	return;
	// }
	long i = std::atol(literal.c_str());
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max()) {
		std::cout << "Int: Out of range." << std::endl;
		return;
	}
	std::cout << "Int: " << i << std::endl;

}

bool isFloat(const std::string &literal) {
	if (literal.empty() || (literal.length() == 1 && !isdigit(literal[0]))) {
		// std::cout << "Float: Not a valid float literal." << std::endl;
		return false;
	}
	size_t dotCount = 0;
	for (size_t i = 0; i < literal.length(); ++i) {
		if (!isdigit(literal[i]) && !(i == 0 && (literal[i] == '-' 
			|| literal[i] == '+')) && literal[i] != '.' && 
			(!(i == literal.length() - 1 && literal[i] == 'f'))) {
			// std::cout << "Float: Not a valid float literal." << std::endl;
			return false;
		}
		if (literal[i] == '.') {
			dotCount++;
			if (dotCount > 1) {
				// std::cout << "Float: Not a valid float literal." << std::endl;
				return false;
			}
		}
	}
	return true;
}

void convertToFloat(const std::string &literal) {
	if (literal == "nan" || literal == "inf" || literal == "-inf") {
		std::cout << "Float: " << literal << "f" << std::endl;
		return;
	}
	if (literal == ".f" || literal == "-.f" || literal == "+.f") {
		std::cout << "Float: Not a valid float literal." << std::endl;
		return;
	}
	if (literal.empty() || (literal.length() == 1 && !isdigit(literal[0]))) {
		std::cout << "Float: Not a valid float literal." << std::endl;
		return;
	}
	if (literal == "nanf" || literal == "inff" || literal == "-inff") {
		std::cout << "Float: " << literal << std::endl;
		return;
	}
	if (!isFloat(literal)) {
		std::cout << "Float: Not a valid float literal." << std::endl;
		return;
	}
	float f;
	char *endptr;
	f = std::strtof(literal.c_str(), &endptr);
	if (f == HUGE_VALF || f == -HUGE_VALF) {
		std::cout << "Float: Out of range." << std::endl;
		return;
	}
	std::cout << "Float: " << f;
	if (f == static_cast<int>(f)) {
		std::cout << ".0"; // Add .0 if it's an integer value
	}
	std::cout << "f" << std::endl;
}

bool isDouble(const std::string &literal) {
	if (literal.empty() || (literal.length() == 1 && !isdigit(literal[0]))) {
//		std::cout << "Double: Not a valid double literal." << std::endl;
		return false;
	}
	size_t dotCount = 0;
	
	for (size_t i = 0; i < literal.length(); ++i) {

		if (!isdigit(literal[i]) && !(i == 0 && (literal[i] == '-' 
			|| literal[i] == '+')) && literal[i] != '.' && 
			(!(i == literal.length() - 1 && literal[i] == 'f'))) {
//			std::cout << "Double: Not a valid double." << std::endl;
			return false;
		}
		if (literal[i] == '.') {
			dotCount++;
			if (dotCount > 1) {
//				std::cout << "Double: Not a valid double literal." << std::endl;
				return false;
			}
		}
	}
	return true;
}
void convertToDouble(const std::string &literal) {
	if (literal == "nan" || literal == "inf" || literal == "-inf") {
		std::cout << "Double: " << literal << std::endl;
		return;
	}
	if (literal == ".f" || literal == "-.f" || literal == "+.f") {
		std::cout << "Double: Not a valid double literal." << std::endl;
		return;
	}
	if (literal.empty() || (literal.length() == 1 && !isdigit(literal[0]))) {
		std::cout << "Double: Not a valid double literal." << std::endl;
		return;
	}
	double d;
	if (!isDouble(literal)) {
		std::cout << "Double: Not a valid double literal." << std::endl;
		return;
	}
	char *endptr;
	d = std::strtod(literal.c_str(), &endptr);
	if (d == HUGE_VAL || d == -HUGE_VAL) {
		std::cout << "Double: Out of range." << std::endl;
		return;
	}
	std::cout << "Double: " << d;
	if (d == static_cast<int>(d)) {
		std::cout << ".0"; // Add .0 if it's an integer value
	}
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
	if (literal.empty()) {
		std::cout << "Error: Empty string provided." << std::endl;
		return;
	}
	else if (literal == ".f" || literal == "-.f" || literal == "+.f" ||
				literal == "." || literal == "-." || literal == "+.") {
		std::cout << "Error: Invalid literal format." << std::endl;
		return;
	}
	convertToChar(literal);
	convertToInt(literal);
	convertToFloat(literal);
	convertToDouble(literal);
}
