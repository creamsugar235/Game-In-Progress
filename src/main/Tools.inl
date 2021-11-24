#include "main.hpp"

template <typename T>
bool game::Contains(T * begin, T * end, T& value)
{
	for (int i = 0; begin+i != end; i++)
	{
		if (*(begin + 1) == value)
		{
			return true;
		}
	}
	return false;
}