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

//? -------------------------- comparison_operators -------------------------- */

bool	Fixed::operator>(const Fixed& other)
{
	if (this->_fixedPoint > other._fixedPoint) return (true);
	else return (false);
}

bool	Fixed::operator<(const Fixed& other)
{
	if (this->_fixedPoint < other._fixedPoint) return (true);
	else return (false);
}

bool	Fixed::operator>=(const Fixed& other)
{
	if (this->_fixedPoint >= other._fixedPoint) return (true);
	else return (false);
}

bool	Fixed::operator<=(const Fixed& other)
{
	if (this->_fixedPoint <= other._fixedPoint) return (true);
	else return (false);
}

bool	Fixed::operator==(const Fixed& other)
{
	if (this->_fixedPoint == other._fixedPoint) return (true);
	else return (false);
}

bool	Fixed::operator!=(const Fixed& other)
{
	if (this->_fixedPoint != other._fixedPoint) return (true);
	else return (false);
}

//? --------------------------- arithmeti_operators -------------------------- */

Fixed	Fixed::operator+(const Fixed& other)
{
	return (Fixed(this->_fixedPoint + other._fixedPoint));
}

Fixed	Fixed::operator-(const Fixed& other)
{
	return (Fixed(this->_fixedPoint - other._fixedPoint));
}

Fixed	Fixed::operator*(const Fixed& other)
{
	return (Fixed(this->_fixedPoint * other._fixedPoint));
}

Fixed	Fixed::operator/(const Fixed& other)
{
	return (Fixed(this->_fixedPoint / other._fixedPoint));
}
//? ---------------------- increment/decrement_operators --------------------- */

Fixed&	Fixed::operator++()
{
	++this->_fixedPoint;
	return (*this);
}

Fixed&	Fixed::operator++(int)
{
	++this->_fixedPoint;
	return (*this);
}
// Fixed&	Fixed::operator--()
// Fixed&	Fixedoperator--(Fixed& other)

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

