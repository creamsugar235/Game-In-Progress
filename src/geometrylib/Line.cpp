#include "main.hpp"

namespace geo
{
	Line::Line()
	{
	}

	Line::Line(const Point& a, const Point& b)
	{
		this->_a = a;
		this->_b = b;
		this->_length = Calc::Distance(this->_a, this->_b);
		this->_angle = Calc::GetAngle(this->_a, this->_b);
	}

	Line::Line(Pointer<Point> a, Pointer<Point> b)
	{
		this->_a = a;
		this->_b = b;
		this->_length = Calc::Distance(this->_a, this->_b);
		this->_angle = Calc::GetAngle(this->_a, this->_b);
	}

	Line::Line(const Line& l)
	{
		this->_a = l.a();
		this->_b = l.b();
		this->_length = Calc::Distance(this->_a, this->_b);
		this->_angle = Calc::GetAngle(this->_a, this->_b);
	}

	Line::Line(Pointer<Line> l)
	{
		this->_a = l->a();
		this->_b = l->b();
		this->_length = Calc::Distance(this->_a, this->_b);
		this->_angle = Calc::GetAngle(this->_a, this->_b);
	}

	Line::~Line()
	{
	}

	bool Line::operator==(const Line& l) const
	{
		return (this->_a == l.a() && this->_b == l.b());
	}

	bool Line::operator!=(const Line& l) const
	{
		return !(this->_a == l.a() && this->_b == l.b());
	}

	Point Line::a() const
	{
		return this->_a;
	}

	double Line::angle() const
	{
		return _angle;
	}

	Point Line::b() const
	{
		return this->_b;
	}

	Point Line::GetPointAlongLine(double distance, bool startFromA) const
	{
		Point begin = startFromA ? this->_a : this->_b;
		return Calc::GetPointOnCircle(begin, distance, this->_angle);
	}

	double Line::length() const
	{
		return this->_length;
	}

	void Line::Move(double offsetX, double offsetY)
	{
		this->_a.Move(offsetX, offsetY);
		this->_b.Move(offsetX, offsetY);
	}

	std::string Line::ToString() const
	{
		return "(" + this->_a.ToString() + ", " + this->_b.ToString() + ")";
	}

	std::tuple<std::tuple<double, double>, std::tuple<double, double>> Line::ToTuple() const
	{
		return std::tuple<std::tuple<double, double>, std::tuple<double, double>>(this->_a.ToTuple(), this->_b.ToTuple());
	}

	void Line::Rotate(const Point& pivot, double angle)
	{
		this->_a.Rotate(pivot, angle);
		this->_b.Rotate(pivot, angle);
		Update();
	}

	void Line::Rotate(Pointer<Point> pivot, double angle)
	{
		this->_a.Rotate(pivot, angle);
		this->_b.Rotate(pivot, angle);
		Update();
	}

	void Line::Update()
	{
		this->_length = Calc::Distance(this->_a, this->_b);
		this->_angle = Calc::GetAngle(this->_a, this->_b);
	}
}