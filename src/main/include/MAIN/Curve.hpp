#include "../GEO/main.hpp"
#include <functional>

namespace game
{
	class Curve;
	class Curve
	{
		public:
			std::function<double(double)> function;
			double length;
			geo::Point origin;
			Curve();
			Curve(const std::function<double(double)>& f, const double& length, const geo::Point& origin);
			Curve(const Curve& c);
			~Curve();
			
	};

	bool operator|(const geo::Point& p, const Curve& c);
}