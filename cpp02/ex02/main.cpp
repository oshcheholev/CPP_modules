#include <iostream>
#include <climits>

#include "Fixed.hpp"

// ANSI color codes for terminal output
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void printTitle(const std::string& title) {
// Print a title in green
std::cout << "\n" << GREEN << "--- " << title << "---" << RESET << std::endl;
std::cout << GREEN << "--------------------------------------" << RESET << std::endl;
}

void testArithmeticOperators() {
    printTitle("Arithmetic Operators");
    
    Fixed a(10.5f); // we create a Fixed object called a with a float value of 10.5
    Fixed b(2.25f); // we create a Fixed object called b with a float value of 2.25
    
    std::cout << "a = " << a << ", b = " << b << std::endl; // we print the values of a and b
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;
    
    // Test division by zero
    Fixed zero;
    std::cout << "a / 0 = ";
    std::cout << (a / zero) << std::endl;
}

void testComparisonOperators() {
    printTitle("Comparison");
    
    Fixed a(42.42f);
    Fixed b(42.42f);
    Fixed c(10);
    
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != c: " << (a != c) << std::endl;
    std::cout << "a > c: " << (a > c) << std::endl;
    std::cout << "c < b: " << (c < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "c <= b: " << (c <= b) << std::endl;
}

void testIncrementDecrement() {
    printTitle("Increment/Decrement");
    
    Fixed a(0);
    int bb = a.toInt(); // Convert Fixed to int for display
    std::cout << "1a = " << a << "  bb " << bb << std::endl;
    a++;
    bb = a.toInt(); // Convert Fixed to int for display
    std::cout << "1a++ " << a << "  bb " << bb << std::endl;

    std::cout << "++a = " << ++a << std::endl;
    std::cout << "a = " << a.toInt() << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "a = " << a.toInt() << std::endl;
    
    std::cout << "--a = " << --a << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "a-- = " << a-- << std::endl;
    std::cout << "a = " << a << std::endl;
}

void testMinMax() {
    printTitle("Min/Max");
    
    Fixed a(10.1f);
    Fixed b(10.2f);
    Fixed const c(42.42f);
    Fixed const d(-42.42f);
    
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    
    std::cout << "min(a,b) = " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a,b) = " << Fixed::max(a, b) << std::endl;
    std::cout << "min(c,d) = " << Fixed::min(c, d) << std::endl;
    std::cout << "max(c,d) = " << Fixed::max(c, d) << std::endl;
}


int main(void) {
    printTitle("Original Test from Subject");
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    // Additional comprehensive tests
    testArithmeticOperators(); 
    testComparisonOperators();
    testIncrementDecrement();
    testMinMax();

    return 0;
}