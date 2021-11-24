#include "../main.hpp"
#include <iostream>

namespace game
{

	std::ostream& operator<<(std::ostream& os, Vector const& v)
	{
		std::string s;
		std::string space;
		s = "Vector: [Is Active: " + std::to_string(v.isActive) + "] ( vel: " + std::to_string(v.vel) + ", vel Loss Per Update: " + std::to_string(v.velDegredation) + ", Rotation: ";
		s = s + std::to_string(v.rotation) + ", Rotation Loss Per Update: " + std::to_string(v.rotationDegredation) + ")";
		return os << s;
	}

	Vector::Vector()
	{
	}

	Vector::Vector(const Vector& v)
	{
		start = v.start;
		direction = v.direction;
		vel = v.vel;
		velDegredation = v.velDegredation;
		rotation = v.rotation;
		rotationDegredation = v.rotationDegredation;
	}
	
	Vector::~Vector()
	{
	}

	void Vector::Update()
	{
		if (isActive)
		{
			vel -= (vel * velDegredation);
			rotation -= (rotation * rotationDegredation);
		}
		if ((vel * velDegredation) < velDegredation && (rotation * rotationDegredation) < rotationDegredation)
		{
			isActive = false;
			vel = 0;
			rotation = 0;
		}
	}
}