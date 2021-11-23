#pragma once
#include <vector>

namespace game
{
	class Entity;
	namespace ui
	{
		class Button;
		class Clickable;

		class Clickable : Entity
		{
			private:
				std::vector<void (*)()> _onClickCalls;
			public:
				Clickable();
				~Clickable();
				virtual void AddOnClickFunction(void (*function)());
				void OnMouseDown() override;
		};

		class Button : Clickable
		{
		};
	}
}