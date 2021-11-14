#pragma once
#include <chrono>
#include <iostream>
#include <map>
#include <random>
#include <thread>
#include "GEO/main.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "headers/Collider.hpp"
#include "headers/Entity.hpp"
#include "headers/Game.hpp"
#include "headers/Layer.hpp"
#include "headers/Layer.hpp"
#include "headers/Misc.hpp"
#include "headers/Player.hpp"
#include "headers/UI.hpp"

namespace game
{
	class Game;
	class Player;
	class Time;
	class TileMap;
	struct Vector;

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

	template <typename T>
	bool Contains(T * start, T * end, T& value);
	std::ostream& operator<<(std::ostream &os, Collider const& c);
	std::ostream& operator<<(std::ostream &os, Vector const& v);

	namespace enums{
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

	class Time final
	{
		public:
			typedef std::chrono::steady_clock clock;
			static inline std::chrono::time_point<clock> time = clock::now();
			static inline double deltaTime = -1;
			static void Tick();
	};
}
#include "Tools.inl"