#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:

		Fixed();
		Fixed(int const raw);
		Fixed(float const floaty);
		Fixed(const Fixed &loco);
		
		Fixed&				operator=(const Fixed& other);
		bool				operator>(const Fixed& other);
		bool				operator<(const Fixed& other);
		bool				operator>=(const Fixed& other);
		bool				operator<=(const Fixed& other);
		bool				operator==(const Fixed& other);
		bool				operator!=(const Fixed& other);

		Fixed				operator+(const Fixed& other);
		Fixed				operator-(const Fixed& other);
		Fixed				operator*(const Fixed& other);
		Fixed				operator/(const Fixed& other);

		Fixed&				operator++();
		Fixed				operator++(int);
		Fixed&				operator--();
		Fixed				operator--(int);

		static Fixed&		min(Fixed& a, Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);

		float				toFloat(void) const;
		int					toInt(void) const;
		int					getRawBits(void) const;
		void				setRawBits(int const raw);

		~Fixed();

	private:

		int					_fixedPoint;
		static const int	_numFractionalBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif