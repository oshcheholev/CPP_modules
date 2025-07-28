
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
	} else {
		std::cout << "Character: Not a valid character literal." << std::endl;
	}
}

void convertToInt(const std::string &literal) {
	if (literal.empty() || (literal.length() == 1 && !isdigit(literal[0]))) {
		std::cout << "Int: Not a valid integer literal." << std::endl;
		return;
	}
	long i = std::atol(literal.c_str());
	if (literal == "nan" || literal == "inf" || literal == "-inf") {
		std::cout << "Int: Not a valid integer literal." << std::endl;
		return;
	}
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max()) {
		std::cout << "Int: Out of range." << std::endl;
		return;
	}
	std::cout << "Int: " << i << std::endl;

}

void convertToFloat(const std::string &literal) {
	if (literal == "nan" || literal == "inf" || literal == "-inf") {
		std::cout << "Float: " << literal << "f" << std::endl;
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
	float f;
	char *endptr;
	f = std::strtof(literal.c_str(), &endptr);
	if (f == HUGE_VALF || f == -HUGE_VALF) {
		std::cout << "Float: Out of range." << std::endl;
		return;
	}
	std::cout << "Float: " << f << "f" << std::endl;
}

void convertToDouble(const std::string &literal) {
	if (literal == "nan" || literal == "inf" || literal == "-inf") {
		std::cout << "Double: " << literal << std::endl;
		return;
	}
	if (literal.empty() || (literal.length() == 1 && !isdigit(literal[0]))) {
		std::cout << "Double: Not a valid double literal." << std::endl;
		return;
	}
	double d;
	char *endptr;
	d = std::strtod(literal.c_str(), &endptr);
	if (d == HUGE_VAL || d == -HUGE_VAL) {
		std::cout << "Double: Out of range." << std::endl;
		return;
	}
	std::cout << "Double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
	convertToChar(literal);
	convertToInt(literal);
	convertToFloat(literal);
	convertToDouble(literal);
}
