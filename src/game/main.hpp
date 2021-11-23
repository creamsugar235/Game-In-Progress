#pragma once
#include <iostream>
#include <random>
#include <thread>
#include "GEO/main.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "headers/Collider.hpp"
#include "headers/ComplexLine.hpp"
#include "headers/Curve.hpp"
#include "headers/Entity.hpp"
#include "headers/Game.hpp"
#include "headers/Generator.hpp"
#include "headers/Layer.hpp"
#include "headers/Layer.hpp"
#include "headers/Misc.hpp"
#include "headers/Noise.hpp"
#include "headers/Player.hpp"
#include "headers/UI.hpp"

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