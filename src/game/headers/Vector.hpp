#pragma once
#include <ostream>

namespace game
{
	struct Vector;
	std::ostream& operator<<(std::ostream &os, Vector const& v);

	struct Vector
	{
		public:
			Vector();
			Vector(const Vector& v);
			~Vector();
			void Update();
			geo::Point start = geo::Infinity;
			geo::Point direction;
			double speed = 0;
			double speedDegredation = 0;
			double rotation = 0;
			double rotationDegredation = 0;
			bool isActive = true;
	};
}