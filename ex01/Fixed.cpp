#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_numFractionalBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const raw)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = raw << _numFractionalBits;
}

Fixed::Fixed(float const floaty)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(floaty * (1 << _numFractionalBits));
}

Fixed::Fixed(const Fixed& loco)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = loco;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)

{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&other != this)
		this->_fixedPoint = other._fixedPoint;
	return (*this);
}

int	Fixed::getRawBits() const
{
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_fixedPoint / (1 << _numFractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPoint >> _numFractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return (os);
}

