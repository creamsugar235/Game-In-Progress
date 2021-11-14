#include "GEO/main.hpp"
namespace game
{
	class Collider;
	class Entity;
	class Game;

	class Entity
	{
		protected:
			std::string _name = "";
			Collider _collider;
			bool _drawable = true;
			int _texture;
		public:
			std::vector<geo::Pointer<Entity>> children;
			Entity();
			~Entity();
			virtual bool operator==(const Entity& other) const;
			virtual bool drawable() const;
			virtual int texture() const;
			virtual std::string name() const;
			virtual int GetHash() const;
			virtual Collider GetCollider() const;
			virtual void OnMouseDown();
			virtual void OnMouseEnter();
			virtual void OnMouseExit();
			virtual void OnMouseOver();
			virtual void Start();
			virtual void Update();
			void UpdateChildren();
		friend class Game;
	};
}