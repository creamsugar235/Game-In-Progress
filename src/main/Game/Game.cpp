#include "../main.hpp"
namespace game
{
	Game::Game(std::string name)
	{
		this->_name = name;
	}

	void Game::GameDisplay()
	{
		_window.clear();
		auto iter = _level.layers.begin();
		//display each layer
		while (iter != _level.layers.end())
		{
			//display each entity
			auto iter2 = iter->second.entities.begin();
			while (iter2 != iter->second.entities.end())
			{
				//REMEMBER TO FILTER FOR WHACK TEXTURE ENUM VALUES
				if (iter2->get().IsDrawable() && IsInView(iter2->get()))
				{
					if (!iter2->get().children.size())
					{
						sf::Sprite s = sf::Sprite(*iter2->get().GetTexture());
						s.setPosition(sf::Vector2f(iter2->get().GetCollider().x(), iter2->get().GetCollider().y()));
						s.setScale(sf::Vector2f(iter2->get().GetScale().x, iter2->get().GetScale().y));
						s.rotate(geo::Calc::Degrees(iter2->get().GetRotation()));
						this->_window.draw(s);
					}
				}
				if (iter2->get().children.size())
				{
					RecursiveDisplay(&(iter2->get()));
				}
				iter2++;
			}
			iter++;
		}
		sf::Sprite p = sf::Sprite(*_p.GetTexture());
		p.setPosition(sf::Vector2f(_p.GetCollider().x(), _p.GetCollider().y()));
		p.setScale(sf::Vector2f(_p.GetScale().x, _p.GetScale().y));
		p.rotate(geo::Calc::Degrees(_p.GetRotation()));
		this->_window.draw(p);
		_window.display();
	}

	void Game::Load()
	{
		for (int i = 0; i < enums::end; i++)
		{
			sf::Texture t;
			if (!t.loadFromFile(TexturePath.find(i)->second))
			{
				throw new geo::Exception("File not Found Error");
			}
			this->textures.insert(std::pair<int, sf::Texture>(i, t));
		}
	}

	bool Game::IsInView(const game::Entity& e)
	{
		Collider camBox = Collider();
		sf::FloatRect c = this->_camera.getViewport();
		camBox.AddPoint(geo::Point((double)c.left, (double)c.top));
		camBox.AddPoint(geo::Point((double)c.left +(double)c.width, c.top));
		camBox.AddPoint(geo::Point((double)c.left + c.width, (double)c.top + c.height));
		camBox.AddPoint(geo::Point((double)c.left, (double)c.top + c.height));
		return camBox.IsColliding(e.GetCollider());
	}

	void Game::SetUp()
	{
		_p.GetCollider().AddPoint(geo::Point(10, 0));
		_p.GetCollider().AddPoint(geo::Point(10, 30));
		_p.GetCollider().AddPoint(geo::Point(40, 0));
		_p.GetCollider().AddPoint(geo::Point(40, 30));
	}

	void Game::RecursiveDisplay(Entity * e)
	{
		if (e->children.size())
		{
			if (e->IsDrawable() && IsInView(*e))
			{
				sf::Sprite s = sf::Sprite(*e->GetTexture());
				s.setPosition(sf::Vector2f(e->GetCollider().x(), e->GetCollider().y()));
				s.setScale(sf::Vector2f(e->GetScale().x, e->GetScale().y));
				s.rotate(geo::Calc::Degrees(e->GetRotation()));
				this->_window.draw(s);
			}
			for (Entity child: e->children)
			{
				if (child.IsDrawable() && IsInView(*e))
				{
					sf::Sprite s = sf::Sprite(*child.GetTexture());
					s.setPosition(sf::Vector2f(child.GetCollider().x(), child.GetCollider().y()));
					s.setScale(sf::Vector2f(child.GetScale().x, child.GetScale().y));
					s.rotate(geo::Calc::Degrees(child.GetRotation()));
					this->_window.draw(s);
				}
				RecursiveDisplay(&child);
			}
		}
		else
		{
			if (e->IsDrawable() && IsInView(*e))
			{
				sf::Sprite s = sf::Sprite(*e->GetTexture());
				s.setPosition(sf::Vector2f(e->GetCollider().x(), e->GetCollider().y()));
				s.setScale(sf::Vector2f(e->GetScale().x, e->GetScale().y));
				s.rotate(geo::Calc::Degrees(e->GetRotation()));
				this->_window.draw(s);
			}
		}
	}

	void Game::Run()
	{
		std::cout<<"Run()"<<std::endl;
		Time __t__();
		Load();
		SetUp();
		_window.create(sf::VideoMode(500, 500), "bruh");
		_camera = _window.getDefaultView();
		_camera.setSize(500, -500); 
		_window.setView(_camera);
		while (_window.isOpen())
		{
			sf::Event event;
			while (_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					_window.close();
				}
			}
			_camera.setCenter(sf::Vector2f(_p.GetCollider().x(), _p.GetCollider().y()));
			_window.setView(_camera);
			Time::Tick();
			Update();
			GameDisplay();
		}
	}

	void Game::Update()
	{
		_p.Update();
		// each layer from Game::_level
		auto layer = _level.layers.end();
		while (layer != _level.layers.begin())
		{
			// each entity from the layer
			auto entity = layer->second.entities.begin();
			while (entity != layer->second.entities.end())
			{
				auto e = layer->second.entities.begin();
				while (e != layer->second.entities.end())
				{
					if (e->get().GetCollider()._isActive)
					{
						for (geo::Point p: entity->get().GetCollider().ReturnPoints())
						{
							p = geo::Point(p.x + entity->get().GetCollider().x(), p.y + entity->get().GetCollider().y());
							Entity tmp = (*entity).get();
							std::vector<Entity *> collided;
							for (auto val = e->get().GetCollider()._collidedEntities.begin(); val != e->get().GetCollider()._collidedEntities.end(); val++)
							{
								collided.push_back(&((*val).get()));
							}
							auto start = collided.begin();
							auto end = collided.end();
							if (e->get().GetCollider().IsIn(p) && !std::count(start, end, &tmp))
							{
								entity->get().GetCollider().OnCollisionEnter(*e);
							}
							else if (e->get().GetCollider().IsIn(p) && std::count(start, end, &tmp))
							{
								entity->get().GetCollider().OnCollisionStay(*e);
							}

							else if (std::count(start, end, &tmp))
							{
								entity->get().GetCollider().OnCollisionExit(*e);
							}
						}
					}

					auto mouse = sf::Mouse::getPosition(_window);
					if (!e->get().children.size())
					{
						if (e->get().GetCollider().IsIn(geo::Point(mouse.x, mouse.y)))
						{
							e->get().OnMouseOver();
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Middle))
							{
								e->get().OnMouseDown();
							}
						}
					}
					
					if (!e->get().children.size())
					{
						e->get().Update();
					}

					else
					{
						e->get().Update();
						e->get().UpdateChildren();
					}
					e++;
				}
				entity++;
			}
			layer--;
		}
	}

	Game::~Game()
	{
	}

	void Game::UIDisplay()
	{
	}
}