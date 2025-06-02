#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int                 _fixedPointValue;
		static const int    _fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();

		Fixed& operator=(const Fixed& otherFixed);

		int getRawBits(void) const;
		void setRawBits(int const raw);

};

#endif // FIXED_HPP