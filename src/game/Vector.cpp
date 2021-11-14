#include "main.hpp"
#include <iostream>

namespace game
{

	std::ostream& operator<<(std::ostream& os, Vector const& v)
	{
		std::string s;
		std::string space;
		s = "Vector: [Is Active: " + std::to_string(v.isActive) + "] ( Speed: " + std::to_string(v.speed) + ", Speed Loss Per Update: " + std::to_string(v.speedDegredation) + ", Rotation: ";
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
		speed = v.speed;
		speedDegredation = v.speedDegredation;
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
			speed -= (speed * speedDegredation);
			rotation -= (rotation * rotationDegredation);
		}
		if ((speed * speedDegredation) < speedDegredation && (rotation * rotationDegredation) < rotationDegredation)
		{
			isActive = false;
			speed = 0;
			rotation = 0;
		}
	}
}