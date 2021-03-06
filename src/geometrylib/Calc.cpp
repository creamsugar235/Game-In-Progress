#include "main.hpp"
namespace geo
{
	double Calc::Degrees(double angle)
	{
		return angle * (180 / M_PI);
	}

	double Calc::Diagonal(double width, double height)
	{
		return sqrt(pow(width, 2) + pow(height, 2));
	}

	double Calc::Distance(const geo::Point &a, const geo::Point &b)
	{
		double dis = (pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
		if (dis < 0) {dis *= -1;}
		return sqrt(dis);
	}

	double Calc::Distance(Pointer<geo::Point> a, Pointer<geo::Point> b)
	{
		double dis = (pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
		if (dis < 0) {dis *= -1;}
		return sqrt(dis);
	}

	double Calc::GetAngle(const geo::Point &a, const geo::Point &b, const geo::Point &c)
	{
		double result = atan2(c.y - b.y, c.x - b.x) - atan2(a.y - b.y, a.x - b.x);
		result = result < 0 ? -result : (M_PI * 2) - result;
		return result;
	}

	double Calc::GetAngle(Pointer<Point> a, Pointer<Point> b, Pointer<Point> c)
	{
		double result = atan2(c->y - b->y, c->x - b->x) - atan2(a->y - b->y, a->x - b->x);
		result = result < 0 ? -result : (M_PI * 2) - result;
		return result;
	}

	double Calc::GetAngle(double slope)
	{
		return atan(slope);
	}	

	double Calc::GetAngle(const Point& center, const Point& point)
	{
		Point third = center.x > point.x ? Point(center.x + 1, center.y) : Point(center.x - 1, center.y);
		return GetAngle(point, center, third);
	}

	double Calc::GetAngle(Pointer<Point> center, Pointer<Point> point)
	{
		Point third = center->x > point->x ? Point(center->x + 1, center->y) : Point(center->x - 1, center-> y);
		return GetAngle(point, center, third);
	}

	Point Calc::GetPointOnCircle(const Point& center, double radius, double angle)
	{
		radius = radius < 0 ? -radius : radius;
		double x = center.x + (radius * cos(angle));
		double y = center.y + (radius * sin(angle));
		return Point(x, y);
	}	

	Point Calc::GetPointOnCircle(Pointer<Point> center, double radius, double angle)
	{
		radius = radius < 0 ? -radius : radius;
		double x = center->x + (radius * cos(angle));
		double y = center->y + (radius * sin(angle));
		return Point(x, y);
	}

	double Calc::GetSlope(const Point& a, const Point& b)
	{
		if (a.y == b.y || a.x == b.x)
		{return 0;}
		return (b.y - a.y) / (b.x - a.x);
	}

	double Calc::GetSlope(Pointer<Point> a, Pointer<Point> b)
	{
		if (a->y == b->y || a->x == b->x)
		{return 0;}
		return (b->y - a->y) / (b->x - a->x);
	}

	bool Calc::Intersecting(const Line& a, const Line& b, bool isInfLine)
	{
		return PointOfIntersect(a, b, isInfLine) != Infinity;
	}

	bool Calc::Intersecting(Pointer<Line> a, Pointer<Line> b, bool isInfLine)
	{
		return PointOfIntersect(a, b, isInfLine) != Infinity;
	}

	Point Calc::PointOfIntersect(const Line& a, const Line& b, bool isInfLine)
	{
		auto det = [](std::tuple<double, double> a, std::tuple<double, double> b) -> double
		{
			return std::get<0>(a) * std::get<1>(b) - std::get<1>(a) * std::get<0>(b);
		};

		auto xdiff = std::tuple<double, double>(a.a().x - a.b().x, b.a().x - b.b().x);
		auto ydiff = std::tuple<double, double>(a.a().y - a.b().y, b.a().y - b.b().y);
		double div = det(xdiff, ydiff);
		if (div == 0) {return Infinity;}
		auto d = std::tuple<double, double>(det(std::get<0>(a.ToTuple()), std::get<1>(a.ToTuple())), det(std::get<0>(b.ToTuple()), std::get<1>(b.ToTuple())));
		double x = det(d, xdiff) / div;
		double y = det(d, ydiff) / div;
		Point p = Point(x, y);
		if (isInfLine) {return p;}
		if ((Distance(a.a(), p) + Distance(a.b(), p) == a.length()) && (Distance(b.a(), p) + Distance(b.b(), p) == b.length()))
		{
			return p;
		}
		return Infinity;
	}

	Point Calc::PointOfIntersect(Pointer<Line> a, Pointer<Line> b, bool isInfLine)
	{
		auto det = [](std::tuple<double, double> a, std::tuple<double, double> b) -> double
		{
			return std::get<0>(a) * std::get<1>(b) - std::get<1>(a) * std::get<0>(b);
		};

		auto xdiff = std::tuple<double, double>(a->a().x - a->b().x, b->a().x - b->b().x);
		auto ydiff = std::tuple<double, double>(a->a().y - a->b().y, b->a().y - b->b().y);
		double div = det(xdiff, ydiff);
		if (div == 0) {return Infinity;}
		auto d = std::tuple<double, double>(det(std::get<0>(a->ToTuple()), std::get<1>(a->ToTuple())), det(std::get<0>(b->ToTuple()), std::get<1>(b->ToTuple())));
		double x = det(d, xdiff) / div;
		double y = det(d, ydiff) / div;
		Point p = Point(x, y);
		if (isInfLine) {return p;}
		if ((Distance(a->a(), p) + Distance(a->b(), p) == a->length()) && (Distance(b->a(), p) + Distance(b->b(), p) == b->length()))
		{
			return p;
		}
		return Infinity;	
	}	
}