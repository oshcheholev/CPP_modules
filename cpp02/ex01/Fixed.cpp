#include <iostream>
#include <cmath>
#include "Fixed.hpp"


Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
} // Default constructor initializes _fixedPointValue to 0

// New constructors
Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
} // Constructor that initializes the fixed-point value from an integer

Fixed::Fixed(const float value) : _fixedPointValue(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {
    std::cout << "Float constructor called" << std::endl;
} // Constructor that initializes the fixed-point value from a float


Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
} // Copy constructor initializes the object by copying the value from another Fixed object

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
} // Destructor cleans up the Fixed object, though no dynamic memory is used here

Fixed& Fixed::operator=(const Fixed& otherFixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &otherFixed) {
        this->_fixedPointValue = otherFixed.getRawBits();
    }
    return *this;
} // Copy assignment operator assigns the value from another Fixed object to this one

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
} // Returns the raw fixed-point value stored in the object

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
} // Sets the raw fixed-point value to the specified integer value

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits; 
} // Converts the fixed-point value to an integer

float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
} // Converts the fixed-point value to a float

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
} // Overloads the output stream operator to print the fixed-point value as a float