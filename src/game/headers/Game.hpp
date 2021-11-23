#pragma once
#include "SFML/Graphics.hpp"
#include "Player.hpp"
#include "Layer.hpp"
#include "Level.hpp"
namespace game
{
	class Game;
	class Level;

	class Game final
	{
		private:
			std::string _name;
			sf::RenderWindow _window;
			sf::View _camera;
			Player _p;
			Level _level;
			void RecursiveDisplay(Entity * e);
		public:
			static std::map<int, sf::Texture> textures;
			Game(std::string name);
			~Game();
			void GameDisplay();
			void Load();
			bool IsInView(const Entity& e);
			void Run();
			void SetUp();
			void Update();
			void UIDisplay();
	};
}