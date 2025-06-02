#include <iostream>
#include <cmath>
#include "Fixed.hpp"


Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
} // Default constructor initializes _fixedPointValue to 0

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
// This function is not used in the main example, but it allows setting the raw value directly