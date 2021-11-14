#include "src/geometrylib/main.hpp"
#include <cassert>

void ConvexShape();
void Line();
void Point();
void Pointer();
void Shape();
void Vector();
int main()
{
	ConvexShape();
	/*Line();
	Point();
	Pointer();
	Shape();
	Vector();*/
	return 0;
}

void ConvexShape()
{

	geo::Line l = geo::Line(geo::Point(0, 0), geo::Point(10, 0));
	geo::Line l2 = geo::Line(geo::Point(5, -5), geo::Point(5, 5));
	geo::ConvexShape c;
	c.AddPoint(geo::Point(0, 0));
	c.AddPoint(geo::Point(4, 0));
	c.AddPoint(geo::Point(4, 4));
	c.AddPoint(geo::Point(0, 4));
	std::cout<<c.IsIn(geo::Point(2, 2))<<std::endl;
}