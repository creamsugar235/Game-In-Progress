#pragma once
#include <map>
#include <functional>
#include "GEO/main.hpp"
namespace game
{
	class Collider;
	class Entity;
	class Game;
	class Vector;
	std::ostream& operator<<(std::ostream &os, Collider const& c);

	class Collider : public geo::ConvexShape
	{
		protected:
			std::vector<std::reference_wrapper<Entity>> _collidedEntities;
			bool _isActive = false;
			bool _moves;
			bool _usesGravity;
		public:
			std::map<std::string, std::reference_wrapper<Vector>> vectors;
			Collider();
			Collider(std::vector<geo::Point> points);
			virtual ~Collider();
			void Update();
			virtual int GetHash() const;
			bool IsColliding(const Collider& c);
			virtual void OnCollisionEnter(Entity& entity);
			virtual void OnCollisionStay(Entity& entity);
			virtual void OnCollisionExit(Entity& entity);
		friend class Game;
	};
}