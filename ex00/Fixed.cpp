#include "Fixed.hpp"

const int	Fixed::_numFractionalBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	Fixed::operator=(other);
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
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw << this->_numFractionalBits;
}

