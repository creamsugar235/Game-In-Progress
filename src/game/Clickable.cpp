#include "main.hpp"

namespace game::ui
{
	Clickable::Clickable()
	{
	}

	Clickable::~Clickable()
	{
	}

	void Clickable::AddOnClickFunction(void (*function)())
	{
		_onClickCalls.push_back(function);
	}

	void Clickable::OnMouseDown()
	{
		for (auto f = _onClickCalls.begin(); f != _onClickCalls.end(); f++)
		{
			(*f)();
		}
	}
}