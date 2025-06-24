#include <iostream>
#include <climits>

#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.cpp"


// ANSI color codes for terminal output
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void printTitle(const std::string& title) {
// Print a title in green
std::cout << "\n" << BLUE << "--- " << title << " ---" << RESET << std::endl;
std::cout << BLUE << "-------------------------------" << RESET << std::endl;
}

int main(void) {
    
    Point triangleA(0.0f, 0.0f);
    Point triangleB(0.0f, 3.0f);
    Point triangleC(2.0f, 0.0f);
    Point point(1.0f, 1.0f);
    
    std::cout << "Triangle A: " << triangleA << std::endl;
    std::cout << "Triangle B: " << triangleB << std::endl;
    std::cout << "Triangle C: " << triangleC << std::endl;
    printTitle("POINT  INSIDE  TRIANGLE");
    std::cout << "Point: " << point << std::endl;

    if (bsp(triangleA, triangleB, triangleC, point)) {
        std::cout << GREEN << "Point is inside the triangle." << RESET << std::endl;
    } else {
        std::cout << RED << "Point is outside the triangle." << RESET << std::endl;
    }

    printTitle("POINT  OUTSIDE  TRIANGLE");
    Point outsidePoint(3.0f, 3.0f);
    std::cout << "Outside Point: " << outsidePoint << std::endl;
    if (bsp(triangleA, triangleB, triangleC, outsidePoint)) {
        std::cout << GREEN << "Outside Point is inside the triangle." << RESET << std::endl;
    } else {
        std::cout << RED << "Outside Point is outside the triangle." << RESET << std::endl;
    }

    printTitle("POINT  ON  TRIANGLE  EDGE");
    Point edgePoint(1.0f, 0.0f);
    std::cout << "Edge Point: " << edgePoint << std::endl;
    if (bsp(triangleA, triangleB, triangleC, edgePoint)) {  
        std::cout << GREEN << "Edge Point is inside the triangle." << RESET << std::endl;
    } else {
        std::cout << RED << "Edge Point is outside the triangle." << RESET << std::endl;
    }

    return 0;
}