#pragma once
#include <chrono>

namespace game
{
	class Time;
	class Time final
	{
		public:
			typedef std::chrono::steady_clock clock;
			static inline std::chrono::time_point<clock> time = clock::now();
			static inline double deltaTime = -1;
			static void Tick();
	};
}