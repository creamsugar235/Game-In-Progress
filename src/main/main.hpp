#pragma once
#include <iostream>
#include <random>
#include <thread>
#include "include/GEO/main.hpp"
#include "include/SFML/Graphics.hpp"
#include "include/SFML/Window.hpp"
#include "include/MAIN/Collider.hpp"
#include "include/MAIN/ComplexLine.hpp"
#include "include/MAIN/Curve.hpp"
#include "include/MAIN/Entity.hpp"
#include "include/MAIN/Game.hpp"
#include "include/MAIN/Generator.hpp"
#include "include/MAIN/Layer.hpp"
#include "include/MAIN/Layer.hpp"
#include "include/MAIN/Misc.hpp"
#include "include/MAIN/Noise.hpp"
#include "include/MAIN/Player.hpp"
#include "include/MAIN/UI.hpp"

namespace game
{

	template <typename T>
	bool Contains(T * start, T * end, T& value);

	namespace enums
	{
		enum Texture
		{
			white_tile,
			spike,
			player,
			end
		};
	}

	const std::map<int, std::string> TexturePath = {
		{enums::white_tile, "bin/textures/white_tile.png",},
		{enums::spike, "bin/textures/spike.png",},
		{enums::player, "bin/textures/player.png",}
	};
}
#include "Tools.inl"