#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixedPoint;
		static const int	_numFractionalBits;
	public:
		Fixed();
		Fixed(int const raw);
		Fixed(float const floaty);
		Fixed(const Fixed &loco);
		Fixed& operator=(const Fixed& other);

		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif