#include "main.hpp"

namespace game
{
	ComplexLine::ComplexLine()
	{
	}

	ComplexLine::ComplexLine(const ComplexLine& c)
	{
		for (size_t i = 0; i < c.Count(); i++)
		{
			this->_lines.push_back(c[i]);
		}
	}

	ComplexLine::~ComplexLine()
	{
	}

	const geo::Line& ComplexLine::operator[](size_t index) const
	{
		return _lines.at(index);
	}

	void ComplexLine::Add(const geo::Line& l)
	{
		if (_lines.size())
		{
			/*if (!(l.a() == _lines[_lines.size() - 1].b() || l.b() == _lines[_lines.size() - 1].b()))
			{
				throw geo::Exception("New `Line` must have equivalent starting `Point` to the preceding `Line's` end `Point`");
			}*/
		}
		_lines.push_back(l);
	}

	void ComplexLine::CleanUp()
	{
		for (size_t i = 0; i - 1 < Count(); i++)
		{
			
		}
	}

	bool ComplexLine::Direction() const
	{
		return this->_direction;
	}

	void ComplexLine::Remove(const geo::Line& l)
	{
		int index = 0;
		for (auto iter = _lines.begin(); iter != _lines.end(); iter++)
		{
			if (*iter == l)
			{
				_lines.erase(iter);
				break;	
			}
			index++;
		}
	}

	void ComplexLine::Set(const geo::Line& l, size_t index)
	{
		if (index >= _lines.size())
		{
			throw geo::Exception("Index out of bounds");
		}
		_lines[index] = l;
	}

	void ComplexLine::SetDirection(bool val)
	{
		_direction = val;
	}

	void ComplexLine::Smooth(double intensity)
	{
		intensity = fmod(intensity, 100);
		size_t i = 0;
		if (_direction == Dir::Right)
		{
			for (auto l = _lines.begin() + 2; (l - 2) != _lines.end();l++)
			{
				// If the difference between the angles of two lines is greater than 360 degrees (or 6.28.... radians) * percentage of intensity
				if (abs((l - 2)->angle() - l->angle()) > (2 * M_PI * (intensity / 100)))
				{
					std::cout<<(l - 2)->ToString()<<"\t"<<l->ToString()<<"\t"<<(l - 1)->ToString()<<std::endl;
					geo::Line tmp = geo::Line((l - 2)->b(), l->a());
					*(l - 1) = tmp;
					std::cout<<(l - 1)->ToString()<<" b"<<std::endl;
				}
				i++;
			}
		}

		else
		{
			for (auto l = _lines.rbegin() + 2; (l - 2) != _lines.rend();l++)
			{
				// If the difference between the angles of two lines is greater than 360 degrees (or 6.28.... radians) * percentage of intensity
				if (abs((l - 2)->angle() - l->angle()) > (2 * M_PI * (intensity / 100)))
				{
					std::cout<<(l - 2)->ToString()<<"\t"<<l->ToString()<<"\t"<<(l - 1)->ToString()<<std::endl;
					geo::Line tmp = geo::Line((l - 2)->b(), l->a());
					*(l - 1) = tmp;
					std::cout<<(l - 1)->ToString()<<" b"<<std::endl;
				}
				i++;
			}
		}
	}

	double ComplexLine::Length() const
	{
		double result = 0;
		for (geo::Line l : _lines)
		{
			result += l.length();
		}
		return result;
	}

	size_t ComplexLine::Count() const
	{
		return _lines.size();
	}
}