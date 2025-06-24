#include <iostream>
#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	// Default constructor initializes _x and _y to 0
}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y) {
	// Constructor that initializes the point with given x and y coordinates
}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {
	// Copy constructor initializes the point with the coordinates of another Point object
}

Point::~Point() {
	// Destructor
}

Point& Point::operator=(const Point& other) {
	if (this != &other) {
		// Copy assignment operator assigns the coordinates from another Point object
		this->_x = other.getX();
		this->_y = other.getY();
	}
	return *this;
}

float Point::getX() const {
	// Returns the x coordinate
	return _x.toFloat();
}

float Point::getY() const {
	// Returns the y coordinate
	return _y.toFloat();
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
	// Overloaded output operator for Point class
	os << "Point(" << point.getX() << ", " << point.getY() << ")";
	return os;
}
// This function allows easy printing of Point objects to output streams