#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Point& other) : _x(other._x), _y(other._y)
{
}

Point&	Point::operator=(const Point& other)
{
	if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
	}
	return (*this);
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

float	Point::getX() const
{
	return (this->_x.toFloat());
}

float	Point::getY() const
{
	return (this->_y.toFloat());
}

void	Point::setX(const float x)
{
	this->_x = x;
}

void	Point::setY(const float y)
{
	this->_y = y;
}

Point::~Point()
{
}
