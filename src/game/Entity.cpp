#include "main.hpp"
namespace game
{
	Entity::Entity()
	{
	}
	

	Entity::~Entity()
	{
	}

	bool Entity::operator==(const Entity& other) const
	{
		return (other.GetHash() == this->GetHash()) && (other.drawable() == this->_drawable) && (other.texture() == this->texture());
	}

	bool Entity::drawable() const
	{
		return this->_drawable;
	}

	int Entity::texture() const
	{
		return this->_texture;
	}

	std::string Entity::name() const
	{
		return _name;
	}

	int Entity::GetHash() const
	{
		return this->_collider.GetHash();
	}

	Collider Entity::GetCollider() const
	{
		return this->_collider;
	}

	void Entity::OnMouseDown()
	{
	}

	void Entity::OnMouseEnter()
	{
	}

	void Entity::OnMouseExit()
	{
	}

	void Entity::OnMouseOver()
	{
	}

	void Entity::Start()
	{
	}

	void Entity::Update()
	{
		_collider.Update();
	}

	void Entity::UpdateChildren()
	{
		for (Entity e : this->children)
		{
			e->Update();
			if (e->children.size() > 0)
			{
				e->UpdateChildren();
			}
		}
	}
}