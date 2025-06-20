#include "Point.hpp"
#include <cmath>
#include <iostream>

float myabs(float value) {
	return (value < 0) ? -value : value;
}

float triangleArea(const Point& a, const Point& b, const Point& c) {
    float x1 = a.getX(), y1 = a.getY();
    float x2 = b.getX(), y2 = b.getY();
    float x3 = c.getX(), y3 = c.getY();

    return myabs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0f);
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
	std::cout << "Area difference: " << myabs(areaABC - totalArea) << std::endl;

    return !isOnEdge && myabs(areaABC - totalArea) <= epsilon.toFloat();
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
	// Check if the point is inside the triangle formed by points a, b, and c
	return isPointInTriangleArea(point, a, b, c);
}