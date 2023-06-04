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
		Fixed& operator=(const Fixed& other);
		~Fixed();

		float toFloat( void ) const;
		int toInt( void ) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);


	private:

		int					_fixedPoint;
		static const int	_numFractionalBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif