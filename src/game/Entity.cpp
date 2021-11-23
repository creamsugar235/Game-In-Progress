#include "main.hpp"
namespace game
{
	Entity::Entity()
	{
	}
	
	Entity::Entity(std::string name, sf::Texture * texture, Collider collider, bool drawable, unsigned long long tag)
	{
		this->_name = name;
		this->_texture = texture;
		this->_collider = collider;
		this->_drawable = drawable;
		this->_tag = tag;
	}

	Entity::~Entity()
	{
	}

	bool Entity::operator==(const Entity& other) const
	{
		return (other.GetHash() == this->GetHash()) && (other.IsDrawable() == this->_drawable);
	}

	bool Entity::operator==(Entity& other)
	{
		return (other.GetHash() == this->GetHash()) && (other.IsDrawable() == this->_drawable);
	}

	bool Entity::IsDrawable() const
	{
		return this->_drawable;
	}

	sf::Texture* Entity::GetTexture() const
	{
		return this->_texture;
	}

	std::string& Entity::GetName()
	{
		return _name;
	}

	std::string Entity::GetName() const
	{
		return _name;
	}

	const int Entity::GetHash() const
	{
		return this->_collider.GetHash();
	}

	const Collider& Entity::GetCollider() const
	{
		return this->_collider;
	}

	Collider& Entity::GetCollider()
	{
		return this->_collider;
	}

	geo::Point& Entity::GetScale() const
	{
		return this->_scale;
	}

	void Entity::OnMouseDown()
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
			e.Update();
			if (e.children.size() > 0)
			{
				e.UpdateChildren();
			}
		}
	}

	unsigned long long Entity::GetTag()
	{
		return _tag;
	}
}