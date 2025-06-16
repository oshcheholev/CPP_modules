#include <iostream>
#include <cmath>
#include "Fixed.hpp"


Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}   // Default constructor initializes _fixedPointValue to 0
    // This constructor is called when a Fixed object is created without any initial value
    // It sets the fixed-point value to zero, which is the default state for a Fixed object


// New constructors
Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}   // Constructor that initializes the fixed-point value from an integer
    // This shifts the integer value left by the number of fractional bits to convert it to fixed-point representation
    // The _fractionalBits is a static constant that defines how many bits are used for the fractional part
    // The value is multiplied by 2^_fractionalBits to convert it to fixed-point format
    // _FractionalBits is set to 8, meaning the fixed-point representation has 8 bits for the fractional part
    // So 00000001 << 8 = 00000001 00000000 = 1.0

Fixed::Fixed(const float value) : _fixedPointValue(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {
    std::cout << "Float constructor called" << std::endl;
}   // Constructor that initializes the fixed-point value from a float
    // This multiplies the float value by 2^_fractionalBits and rounds it to the nearest integer
    // The result is then cast to an integer to store it in the fixed-point representation
    // The roundf function is used to ensure proper rounding of the float value before conversion
    // For example, if value is 5.35, it will be stored as roundf(5.35 * 256) = roundf(1376.0) = 1376 in fixed-point format


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
}   // Converts the fixed-point value to an integer
    // This shifts the fixed-point value right by the number of fractional bits to convert it to integer representation
    // For example, if _fixedPointValue is 1280 and _fractionalBits is 8, it will return 5 (1280 >> 8 = 5)

float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}   // Converts the fixed-point value to a float
    // This divides the fixed-point value by 2^_fractionalBits to convert it to float representation
    // The result is cast to float for proper conversion
    // For example, if _fixedPointValue is 1376 and _fractionalBits is 8, it will return 5.35 (1376 / 256 = 5.35)

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}   // Overloads the output stream operator to print the fixed-point value as a float
    // This allows for easy printing of Fixed objects using std::cout
    // For example, if fixed.toFloat() returns 5.35, it will print "5.35" to the output stream
    // This function is defined outside the Fixed class to allow for operator overloading