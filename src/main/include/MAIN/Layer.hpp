#pragma once
#include "../GEO/main.hpp"
#include <functional>
namespace game
{
	class Entity;
	class Layer;

	struct Layer
	{
		public:
			std::string name = "";
			std::vector<std::reference_wrapper<Entity>> entities;
	};
}