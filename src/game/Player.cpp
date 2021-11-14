#include "main.hpp"

namespace game
{
	Player::Player()
	{
		_texture = enums::player;
	}

	void Player::Update()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			_collider.Move(speed * Time::deltaTime, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			_collider.Move(-speed * Time::deltaTime, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (!_collider.vectors.count("jump"))
			{
				_jump.isActive = true;
				_jump.speed = 0.5 * Time::deltaTime;
				_jump.speedDegredation = 0.005;
				_jump.direction = geo::Point(0, 1);
				_collider.vectors.insert(std::pair<std::string, Vector*>("jump", &_jump));
			}
			else
			{
				_jump.isActive = true;
			}
		}
		else
		{
			_jump.isActive = false;
		}

		if (_collider.y() > 0)
		{
			_gravity.isActive = true;
			_gravity.speed = 0.05 * Time::deltaTime;
			_gravity.speedDegredation = 0.005;
			_gravity.direction = geo::Point(0, -1);
			if (!_collider.vectors.count("gravity"))
			{
				_collider.vectors.insert(std::pair<std::string, Vector*>("gravity", &_gravity));
			}
		}
		else
		{
			_gravity.isActive = false;
		}
		std::cout<<_collider<<std::endl;
		_collider.Update();
	}
}