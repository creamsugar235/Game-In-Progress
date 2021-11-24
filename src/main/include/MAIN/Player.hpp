#pragma once
#include "Vector.hpp"
#include "Entity.hpp"
class Player;
class Game;
namespace game
{
	class Player : public Entity
	{
		private:
			Vector _jump;
			Vector _gravity;
		public:
			double speed = 0.02;
			Player();
			void Update() override;
		friend class Game;
	};
}