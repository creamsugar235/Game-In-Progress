#pragma once
#include <map>
#include <string>
namespace game
{
	class Level;

	struct Level
	{
		public:
			std::map<std::string, Layer> layers;
	};
}