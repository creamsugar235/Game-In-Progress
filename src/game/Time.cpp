#include "main.hpp"

namespace game
{
	void Time::Tick()
	{
		std::chrono::time_point<clock> t = clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(t - time).count();
		time = clock::now();
	}
}