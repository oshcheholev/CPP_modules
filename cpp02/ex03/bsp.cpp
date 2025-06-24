#include "Point.hpp"
#include <cmath>
#include <iostream>

// float mySqrt(float value) {
// 	// Function to compute the square root of a number
// 	float result = 0.0f;
// 	float increment = 0.001f; // Increment for approximation

// 	if (value == 0) {
// 		return 0; // Square root of 0 is 0
// 	}
// 	if (value == 1) {
// 		return 1; // Square root of 1 is 1
// 	}
// 	if (value < 0) {
// 		std::cerr << "Error: Cannot compute square root of a negative number." << std::endl;
// 		return -1; // Return an error value
// 	}
// 	for (float i = 0; i <= value; i += increment) {
// 		if (i * i > value) {
// 			break; // Stop when the square exceeds the value
// 		}
// 		result = i; // Update result to the current approximation
// 	}
// 	return result;
// }

float myAbs(float value) {
	return (value < 0) ? -value : value;
}

float triangleArea(const Point& a, const Point& b, const Point& c) {
    float x1 = a.getX(), y1 = a.getY();
    float x2 = b.getX(), y2 = b.getY();
    float x3 = c.getX(), y3 = c.getY();

    return myAbs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0f);
}

bool isPointInTriangleArea(const Point& p, const Point& a, const Point& b, const Point& c) {
	Fixed epsilon(0.0001f);
	// Calculate the area of triangle ABC and the areas of triangles PAB, PBC, and PCA
    float areaABC = triangleArea(a, b, c);
    float areaPAB = triangleArea(p, a, b);
    float areaPBC = triangleArea(p, b, c);
    float areaPCA = triangleArea(p, c, a);

    float totalArea = areaPAB + areaPBC + areaPCA;
	std::cout << "Area ABC: " << areaABC << ", Area PAB: " << areaPAB 
			  << ", Area PBC: " << areaPBC << ", Area PCA: " << areaPCA 
			  << ", Total Area: " << totalArea << std::endl;

	// Check if the point is on the edge of the triangle

	bool isOnEdge = (areaPAB == 0 || areaPBC == 0 || areaPCA == 0);

	std::cout << "Is on edge: " << std::boolalpha << isOnEdge << std::endl;
	std::cout << "Area difference: " << myAbs(areaABC - totalArea) << std::endl;

    return !isOnEdge && myAbs(areaABC - totalArea) <= epsilon.toFloat();
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
	// Check if the point is inside the triangle formed by points a, b, and c
	return isPointInTriangleArea(point, a, b, c);
}