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
		Fixed& operator=(const Fixed& other);
		~Fixed();

		float toFloat( void ) const;
		int toInt( void ) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);


	private:

		int					fixedPoint;
		float				floatFixedPoint;
		static const int	numFractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif