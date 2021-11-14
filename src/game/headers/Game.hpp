#include "SFML/Graphics.hpp"
namespace game
{	class Game;
	class Level;
	class Player;

	class Game final
	{
		private:
			std::string _name;
			sf::RenderWindow _window;
			Player _p;
			Level _level;
			void RecursiveDisplay(Entity * e);
		public:
			std::map<int, sf::Texture> textures;
			Game(std::string name);
			~Game();
			void Display();
			void Load();
			void Run();
			void SetUp();
			void Update();
	};
}