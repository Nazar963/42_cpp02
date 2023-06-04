#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point();
		Point(const Point& other);
		Point&	operator=(const Point& other);
		Point(const float x, const float y);
		Fixed	getX() const;
		Fixed	getY() const;

		~Point();
};

#endif