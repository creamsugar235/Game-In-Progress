#include "game/main.hpp"
#include <fstream>

void makeFiles()
{
	game::Level l = game::Level();
	std::ofstream gameFile = std::ofstream("Levels.lvl", std::ios::out | std::ios::binary);
	game::Layer lay1;
	lay1.name = "layer1";
	lay1.entities.push_back(x)
	gameFile.close();
}