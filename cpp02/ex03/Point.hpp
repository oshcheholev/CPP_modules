
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp" // Include the Fixed class for fixed-point arithmetic
#include <iostream>
#include <cmath> // for roundf function


class Point {
	private:
		Fixed _x;
		Fixed _y;

	public:
		Point(); // Default constructor initializes _x and _y to 0
		Point(Fixed x, Fixed y); // Constructor that initializes the point with given x and y coordinates
		Point(const Point& other); // Copy constructor
		~Point(); // Destructor

		Point& operator=(const Point& other); // Copy assignment operator

		float getX() const; // Returns the x coordinate
		float getY() const; // Returns the y coordinate
};

std::ostream& operator<<(std::ostream& os, const Point& point); // Overloaded output operator for Point class
#endif