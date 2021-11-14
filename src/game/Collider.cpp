#include "main.hpp"
namespace game
{
	Collider::Collider() : geo::ConvexShape()
	{
		this->_isActive = false;
	}

	Collider::Collider(std::vector<geo::Point> points) : geo::ConvexShape(points)
	{
		this->_isActive = true;
	}

	Collider::~Collider()
	{
	}

	std::ostream& operator<<(std::ostream& os, Collider const& c)
	{
		std::string s;
		std::string space;
		space = " ";
		for (geo::Point p: c.ReturnPoints())
		{
			s = s + space + p.ToString();
		}
		return os << s;
	}

	void Collider::Update()
	{
		for (auto v = vectors.begin(); v != vectors.end(); v++)
		{
			if (v->second->isActive)
			{
				this->Move(v->second->direction.x * v->second->speed, v->second->direction.y * v->second->speed);
				if (v->second->rotation)
				{
					for (auto p = _points.begin(); p != _points.end(); p++)
					{
						p->Rotate(v->second->start, v->second->rotation);
					}
				}
				v->second->Update();
			}
		}
	}

	void Collider::OnCollisionEnter(geo::Pointer<Entity>& entity)
	{
		this->_collidedEntities.push_back(entity);
	}

	void Collider::OnCollisionExit(geo::Pointer<Entity>& entity)
	{
		bool contains = false;
		for (unsigned long long i = 0; i < this->_collidedEntities.size(); i++)
		{
			if (*entity == *this->_collidedEntities[i])
			{
				contains = true;
				break;
			}
		}
		if (contains)
		{
			geo::Pointer<Entity> * arr = new geo::Pointer<Entity>[this->_collidedEntities.size()];
			for (unsigned long long i = 0; i < this->_collidedEntities.size(); i++)
			{
				arr[i] = this->_collidedEntities[i];
			}
			unsigned long long index = 0;
			for (unsigned long long i = 0; i < this->_collidedEntities.size(); i++)
			{
				if (*arr[i] == *entity)
				{
					index = i;
					break;
				}
			}
			this->_collidedEntities.erase(std::next(this->_collidedEntities.begin() + (index - 1)));
		}
	}

	void Collider::OnCollisionStay(geo::Pointer<Entity>& entity)
	{
	}

	int Collider::GetHash() const
	{
		if (!this->_points.size())
		{
			return 0;
		}
		std::string s = "";
		for (geo::Point p: this->_points)
		{
			s = s + ", " + p.ToString();
		}
		int h = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			h = h * 31 + static_cast<int>(s[i]);
		}
		return h;
	}
}