#include <iostream>
#include <cmath>
#include "Fixed.hpp"


Fixed::Fixed() : _fixedPointValue(0) {
//    std::cout << "Default constructor called" << std::endl;
}   // Default constructor initializes _fixedPointValue to 0
    // This constructor is called when a Fixed object is created without any initial value
    // It sets the fixed-point value to zero, which is the default state for a Fixed object


// New constructors
Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits) {
//    std::cout << "Int constructor called" << std::endl;
}   // Constructor that initializes the fixed-point value from an integer
    // This shifts the integer value left by the number of fractional bits to convert it to fixed-point representation
    // The _fractionalBits is a static constant that defines how many bits are used for the fractional part
    // The value is multiplied by 2^_fractionalBits to convert it to fixed-point format
    // _FractionalBits is set to 8, meaning the fixed-point representation has 8 bits for the fractional part
    // For example, if value is 5, it will be stored as 5 * 256 = 1280 in fixed-point format

Fixed::Fixed(const float value) : _fixedPointValue(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {
//    std::cout << "Float constructor called" << std::endl;
}   // Constructor that initializes the fixed-point value from a float
    // This multiplies the float value by 2^_fractionalBits and rounds it to the nearest integer
    // The result is then cast to an integer to store it in the fixed-point representation
    // The roundf function is used to ensure proper rounding of the float value before conversion
    // For example, if value is 5.35, it will be stored as roundf(5.35 * 256) = roundf(1376.0) = 1376 in fixed-point format


Fixed::Fixed(const Fixed& other) {
//    std::cout << "Copy constructor called" << std::endl;
    *this = other;
} // Copy constructor initializes the object by copying the value from another Fixed object

Fixed::~Fixed() {
//    std::cout << "Destructor called" << std::endl;
} // Destructor cleans up the Fixed object, though no dynamic memory is used here

Fixed& Fixed::operator=(const Fixed& otherFixed) {
//    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &otherFixed) {
        this->_fixedPointValue = otherFixed.getRawBits();
    }
    return *this;
} // Copy assignment operator assigns the value from another Fixed object to this one

int Fixed::getRawBits(void) const {
//    std::cout << "getRawBits member function called" << std::endl;
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

// OPERATORS OVERLOAD
bool Fixed::operator==(const Fixed& other) const {
    return this->_fixedPointValue == other._fixedPointValue;
}   // Equality operator checks if two Fixed objects have the same fixed-point value

bool Fixed::operator!=(const Fixed& other) const {
    return this->_fixedPointValue != other._fixedPointValue;
}   // Inequality operator checks if two Fixed objects have different fixed-point values

bool Fixed::operator<(const Fixed& other) const {
    return this->_fixedPointValue < other._fixedPointValue;
}   // Less than operator checks if this Fixed object is less than another Fixed object

bool Fixed::operator<=(const Fixed& other) const {
    return this->_fixedPointValue <= other._fixedPointValue;
}   // Less than or equal to operator checks if this Fixed object is less than or equal to another Fixed object

bool Fixed::operator>(const Fixed& other) const {
    return this->_fixedPointValue > other._fixedPointValue;
}   // Greater than operator checks if this Fixed object is greater than another Fixed object

bool Fixed::operator>=(const Fixed& other) const {
    return this->_fixedPointValue >= other._fixedPointValue;
}   // Greater than or equal to operator checks if this Fixed object is greater than or equal to another Fixed object

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}   // Addition operator adds the fixed-point values of two Fixed objects and returns a new Fixed object

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}   // Subtraction operator subtracts the fixed-point values of two Fixed objects and returns a new Fixed object

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}   // Multiplication operator multiplies the fixed-point values of two Fixed objects and returns a new Fixed object

Fixed Fixed::operator/(const Fixed& other) const {
    if (other._fixedPointValue == 0) {
        std::cerr<<"Division by zero"<< std::endl;
        return Fixed(0); // Handle division by zero by returning a Fixed object with value 0
    }
    return Fixed(this->toFloat() / other.toFloat());
}   // Division operator divides the fixed-point values of two Fixed objects and returns a new Fixed object
    // It checks for division by zero and throws an exception if the divisor is zero

Fixed& Fixed::operator++() {
    std::cout << "Pre-increment  " << this->_fixedPointValue << std::endl;
    this->_fixedPointValue++;
    std::cout << "Pre-increment1  " << this->_fixedPointValue << std::endl;

    return *this;
}   // Pre-increment operator increments the fixed-point value by 1 (in fixed-point representation) and returns the updated object

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->_fixedPointValue++;
    return temp;
}   // Post-increment operator increments the fixed-point value by 1 (in fixed-point representation) and returns the original object
    // The int parameter is used to differentiate between pre and post increment

Fixed& Fixed::operator--() {
    this->_fixedPointValue--;
    return *this;
}   // Pre-decrement operator decrements the fixed-point value by 1 (in fixed-point representation) and returns the updated object

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_fixedPointValue--;
    return temp;
}   // Post-decrement operator decrements the fixed-point value by 1 (in fixed-point representation) and returns the original object
    // The int parameter is used to differentiate between pre and post decrement

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}   // Static method to return the minimum of two Fixed objects
    // It compares the fixed-point values and returns the one that is smaller

const Fixed & Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}   // Static method to return the minimum of two Fixed objects (const version)
    // It compares the fixed-point values and returns the one that is smaller

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}   // Static method to return the maximum of two Fixed objects
    // It compares the fixed-point values and returns the one that is larger
const Fixed & Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
    // Static method to return the maximum of two Fixed objects (const version)
    // It compares the fixed-point values and returns the one that is larger

// Fixed::abs() const {
//     return (_fixedPointValue < 0) ? Fixed(-_fixedPointValue) : *this;
// }    

}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}   // Overloads the output stream operator to print the fixed-point value as a float
    // This allows for easy printing of Fixed objects using std::cout
    // For example, if fixed.toFloat() returns 5.35, it will print "5.35" to the output stream
    // This function is defined outside the Fixed class to allow for operator overloading