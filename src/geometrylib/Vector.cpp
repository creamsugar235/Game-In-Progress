#include "main.hpp"

namespace geo
{
	Vector::Vector()
	{
	}
	
	Vector::Vector(Point start, Point direction, double magnitude)
	{
		this->start = start;
		this->direction = direction;
		this->magnitude = magnitude;
	}
}