#include <map>
#include "GEO/main.hpp"
namespace game
{
	class Collider;
	class Entity;
	class Game;
	class Vector;

	class Collider : public geo::ConvexShape
	{
		protected:
			std::vector<geo::Pointer<Entity>> _collidedEntities;
			bool _isActive = false;
			bool _moves;
			bool _usesGravity;
		public:
			std::map<std::string, Vector*> vectors;
			Collider();
			Collider(std::vector<geo::Point> points);
			virtual ~Collider();
			void Update();
			virtual int GetHash() const;
			virtual void OnCollisionEnter(geo::Pointer<Entity>& entity);
			virtual void OnCollisionStay(geo::Pointer<Entity>& entity);
			virtual void OnCollisionExit(geo::Pointer<Entity>& entity);
		friend class Game;
	};
}