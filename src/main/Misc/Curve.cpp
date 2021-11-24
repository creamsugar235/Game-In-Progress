#include "../main.hpp"

namespace game{
	Curve::Curve()
	{
	}

	Curve::~Curve()
	{
	}
	
	Curve::Curve(const std::function<double(double)>& f, const double& length, const geo::Point& p)
	{
		this->function = f;
		this->length = length;
		this->origin = p;
	}

	Curve::Curve(const Curve& c)
	{
		this->function = c.function;
		this->length = c.length;
	}

	bool operator|(const geo::Point& p, const Curve& c)
	{
		geo::Point target;
		target.x = p.x;
		target.y = c.function(abs(c.origin.x - p.x));
		return geo::Calc::Distance(p, target) < 0.01;
	}
}