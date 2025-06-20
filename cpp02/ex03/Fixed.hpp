#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // for roundf function

class Fixed {
	private:
		int                 _fixedPointValue;
		static const int    _fractionalBits = 8;
	public:
		Fixed(); //default constructor initializes _fixedPointValue to 0

		//new constructors
		Fixed(const int value); // constructor that initializes the fixed-point value from an integer
		Fixed(const float value); // constructor that initializes the fixed-point value from a float
		
		Fixed(const Fixed& otherFixed); // copy constructor initializes the object 
		// by copying the value from another Fixed object
		~Fixed(); // destructor cleans up the Fixed object, though no dynamic memory is used here

		Fixed& operator=(const Fixed& otherFixed); // copy assignment operator 
		// assigns the value from another Fixed object to this one

		int getRawBits(void) const; // returns the raw fixed-point value stored in the object
		void setRawBits(int const raw); // sets the raw fixed-point value to the specified integer value

		// new methods
		int toInt(void) const; // converts the fixed-point value to an integer
		float toFloat(void) const; // converts the fixed-point value to a float

		Fixed abs() const; // returns the absolute value of the Fixed object

		//OPERATORS OVERLOAD
		bool operator==(const Fixed& other) const;	// equality operator
		bool operator!=(const Fixed& other) const;	// inequality operator
		bool operator<(const Fixed& other) const;	// less than operator
		bool operator<=(const Fixed& other) const;	// less than or equal to operator
		bool operator>(const Fixed& other) const;	// greater than operator
		bool operator>=(const Fixed& other) const;	// greater than or equal to operator
		Fixed operator+(const Fixed& other) const;	// addition operator
		Fixed operator-(const Fixed& other) const;	// subtraction operator
		Fixed operator*(const Fixed& other) const;	// multiplication operator
		Fixed operator/(const Fixed& other) const;	// division operator
		Fixed& operator++();						// pre-increment 
		Fixed operator++(int);						// post-increment
		Fixed& operator--();						// pre-decrement
		Fixed operator--(int);						// post-decrement

		static Fixed& min(Fixed& a, Fixed& b);	// returns the minimum of two Fixed objects
		static const Fixed& min(const Fixed& a, const Fixed& b); // returns the minimum of two Fixed objects (const version)
		static Fixed& max(Fixed& a, Fixed& b);	// returns the maximum of two Fixed objects
		static const Fixed& max(const Fixed& a, const Fixed& b); // returns the maximum of two Fixed objects (const version)

	};
	std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
	
#endif // FIXED_HPP