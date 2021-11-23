#pragma once
#include "GEO/main.hpp"
#include <functional>

namespace game
{
	class Collider;
	class Entity;
	class Game;

	class Entity
	{
		protected:
			std::string _name = "";
			unsigned long long _tag = 999;
			bool _drawable = true;
			sf::Texture* _texture;
			Collider _collider;
			geo::Point _scale = geo::Point(1, 1);
			double _rotation = 0;
		public:
			std::vector<std::reference_wrapper<Entity>> children;
			Entity();
			Entity(std::string name, sf::Texture* texture, Collider collider, bool drawable = true, unsigned long long tag = 999);
			~Entity();
			virtual bool operator==(const Entity& other) const;
			virtual bool operator==(Entity& other);
			virtual const int GetHash() const;
			virtual void OnMouseDown();
			virtual void OnMouseOver();
			virtual void Start();
			virtual void Update();
			bool IsDrawable() const;
			std::string& GetName();
			std::string GetName() const;
			sf::Texture* GetTexture() const;
			double GetRotation() const;
			const Collider& GetCollider() const;
			Collider& GetCollider();
			geo::Point& GetScale();
			void SetScale(const geo::Point& s);
			void UpdateChildren();
			unsigned long long GetTag();
	};
}