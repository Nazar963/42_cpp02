#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point	a;
	Point	b;
	Point	c;
	Point	point;

	float	var;

	std::cout << "Enter a.x: " << std::endl;
	std::cin >> var;
	a.setX(var);
	std::cout << "Enter a.y: " << std::endl;
	std::cin >> var;
	a.setY(var);
	std::cout << "Enter b.x: " << std::endl;
	std::cin >> var;
	b.setX(var);
	std::cout << "Enter b.y: " << std::endl;
	std::cin >> var;
	b.setY(var);
	std::cout << "Enter c.x: " << std::endl;
	std::cin >> var;
	c.setX(var);
	std::cout << "Enter c.y: " << std::endl;
	std::cin >> var;
	c.setY(var);
	std::cout << "Enter point.x: " << std::endl;
	std::cin >> var;
	point.setX(var);
	std::cout << "Enter point.y: " << std::endl;
	std::cin >> var;
	point.setY(var);

	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;

	return 0;
}