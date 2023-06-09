#include "Point.hpp"

bool sameSide(Point p1, Point p2, Point a, Point b)
{
	int cp1 = (b.getX() - a.getX()) * (p1.getY() - a.getY()) - (b.getY() - a.getY()) * (p1.getX() - a.getX());
	int cp2 = (b.getX() - a.getX()) * (p2.getY() - a.getY()) - (b.getY() - a.getY()) * (p2.getX() - a.getX());

	return (cp1 != 0 && cp2 != 0 && cp1 * cp2 > 0);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	return (sameSide(point, a, b, c) && sameSide(point, b, a, c) && sameSide(point, c, a, b));
}