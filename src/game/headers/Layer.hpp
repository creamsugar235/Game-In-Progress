#include "GEO/main.hpp"
#include <string>
namespace game
{
	class Entity;
	class Layer;

	struct Layer
	{
		public:
			std::string name = "";
			std::vector<geo::Pointer<Entity>> entities = std::vector<geo::Pointer<Entity>>(0);
	};
}