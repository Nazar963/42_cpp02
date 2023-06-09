#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_numFractionalBits = 8;

//? ------------------------------- Constructor ------------------------------ */

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
}

Fixed::Fixed(int const raw)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = raw << _numFractionalBits;
}

Fixed::Fixed(float const floaty)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(floaty * (1 << _numFractionalBits));
}

Fixed::Fixed(const Fixed& loco)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = loco;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

//? -------------------------- assignement_operator -------------------------- */

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (&other != this) this->_fixedPoint = other._fixedPoint;
	return (*this);
}

//? -------------------------- comparison_operators -------------------------- */

bool	Fixed::operator>(const Fixed& other)
{
	return ((this->_fixedPoint > other._fixedPoint) ? true : false);
}

bool	Fixed::operator<(const Fixed& other)
{
	return ((this->_fixedPoint < other._fixedPoint) ? true : false);
}

bool	Fixed::operator>=(const Fixed& other)
{
	return ((this->_fixedPoint >= other._fixedPoint) ? true : false);
}

bool	Fixed::operator<=(const Fixed& other)
{
	return ((this->_fixedPoint <= other._fixedPoint) ? true : false);
}

bool	Fixed::operator==(const Fixed& other)
{
	return ((this->_fixedPoint == other._fixedPoint) ? true : false);
}

bool	Fixed::operator!=(const Fixed& other)
{
	return ((this->_fixedPoint != other._fixedPoint) ? true : false);
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
	return ((this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other)
{
	return ((this->toFloat() / other.toFloat()));
}

//? ---------------------- increment/decrement_operators --------------------- */

Fixed&	Fixed::operator++()
{
	++this->_fixedPoint;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_fixedPoint;
	return temp;
}

Fixed&	Fixed::operator--()
{
	--this->_fixedPoint;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_fixedPoint;
	return temp;
}

//? ------------------------------ min/max_methods ---------------------------- */

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return ((a._fixedPoint < b._fixedPoint) ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return ((a._fixedPoint > b._fixedPoint) ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a._fixedPoint < b._fixedPoint) ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a._fixedPoint > b._fixedPoint) ? a : b);
}

//? ------------------------------ other_methods ----------------------------- */

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

