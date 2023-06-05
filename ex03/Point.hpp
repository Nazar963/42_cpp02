#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	private:
		Fixed	_x;
		Fixed	_y;
	public:
		Point();
		Point(const Point& other);
		Point&	operator=(const Point& other);
		Point(const float x, const float y);
		float	getX() const;
		float	getY() const;
		void	setX(const float x);
		void	setY(const float y);

		~Point();
};

bool sameSide(Point p1, Point p2, Point a, Point b);
bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif