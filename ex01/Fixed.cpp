#include "Fixed.hpp"


#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const raw)
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = raw << this->numFractionalBits;
}

Fixed::Fixed(float const floaty)
{
	std::cout << "Copy constructor called" << std::endl;
	this->floatFixedPoint = roundf(floaty * (1 << this->numFractionalBits));
	// _fixedNb(roundf(flaot * (1 << _fractBits)))
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed& other)

{
	if (&other != this){};
	std::cout << "Copy assignment operator called" << std::endl;
	Fixed::getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw << this->numFractionalBits;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->floatFixedPoint) / (1 << this->numFractionalBits));
}


int	Fixed::toInt(void) const
{
	return (this->fixedPoint >> this->numFractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return (os);
}

