#include "main.hpp"
#include <iostream>

namespace geo
{

	ConvexShape::ConvexShape()
	{
	}

	ConvexShape::ConvexShape(std::vector<Point> points)
	{
		this->_points = points;
		for (unsigned long long i = 0ULL; i < points.size(); i++)
		{
			this->_lines.push_back(Line(points[i], points[(i + 1) % points.size()]));
		}	
	}

	ConvexShape::~ConvexShape()
	{
	}

	double ConvexShape::x() const
	{
		return _x;
	}

	double ConvexShape::y() const
	{
		return _y;
	}

	double ConvexShape::rotation() const
	{
		return _rotation;
	}
	
	ConvexShape ConvexShape::Clone()
	{
		return ConvexShape(this->_points);
	}

	void ConvexShape::AddPoint(const Point& p)
	{
		_points.push_back(p);
		_lines.clear();
		for (unsigned long long i = 0ULL; i < _points.size(); i++)
		{
			this->_lines.push_back(Line(_points[i], _points[(i + 1) % _points.size()]));
		}	
	}

	bool ConvexShape::IsIn(const Point& p) const
	{
		Point max = *max_element(this->_points.begin(), this->_points.end());
		Line line = Line(p, Point(max.x + (1 * max.x > p.x ? 1 : -1), p.y));
		std::vector<Point> listOfIntersections = std::vector<Point>();
		for (auto l = this->_lines.begin(); l != this->_lines.end(); l++)
		{
			if (Calc::Intersecting(*l, line))
			{
				if (!listOfIntersections.size() || !std::count(listOfIntersections.begin(), listOfIntersections.end(), (Calc::PointOfIntersect(*l, line))))
				{
					listOfIntersections.push_back(Calc::PointOfIntersect(*l, line));
				}
			}
		}
		return listOfIntersections.size() % 2;
	}

	void ConvexShape::Move(double offsetX, double offsetY)
	{
		this->_x += offsetX;
		this->_y += offsetY;
		for (auto p = _points.begin(); p != _points.end(); p++)
		{
			p->Move(offsetX, offsetY);
		}
		for (auto l = _lines.begin(); l != _lines.end(); l++)
		{
			l->Move(offsetX, offsetY);
		}
	}

	std::vector<Point> ConvexShape::ReturnPoints() const
	{
		std::vector<Point> v;
		v.resize(_points.size());
		int i = 0;
		for (Point p: _points)
		{
			v[i] = p;
			i++;
		}
		return v;
	}

	void ConvexShape::Scale(double xFactor, double yFactor)
	{
		for (auto p = _points.begin(); p != _points.end(); p++)
		{
			p->x *= xFactor;
			p->y *= yFactor;
		}
		for (auto l = _lines.begin(); l != _lines.end(); l++)
		{
			*l = Line(geo::Point(l->a().x * xFactor, l->a().y * yFactor), geo::Point(l->b().x * xFactor, l->b().y * yFactor));
		}
	}

	std::string ConvexShape::ToString() const
	{
		return "ConvexShape";
	}
}