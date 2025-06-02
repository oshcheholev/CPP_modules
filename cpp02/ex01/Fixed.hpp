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

	};
	std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
	
#endif // FIXED_HPP