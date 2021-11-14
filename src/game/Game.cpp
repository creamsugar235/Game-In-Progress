#include "main.hpp"
namespace game
{
	Game::Game(std::string name)
	{
		this->_name = name;
	}

	void Game::Display()
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
				if (iter2->drawable())
				{
					if (iter2->children.size())
					{
						RecursiveDisplay(&(*iter2));
					}
					else
					{
						sf::Sprite s = sf::Sprite(textures[iter2->texture()]);
						s.setPosition(sf::Vector2f(iter2->_collider._x, iter2->_collider._y));
						this->_window.draw(s);
					}
				}
				iter2++;
			}
			iter++;
		}
		sf::Sprite p = sf::Sprite(textures[_p.texture()]);
		p.setPosition(sf::Vector2f(_p._collider.ReturnPoints()[0].x, _p._collider.ReturnPoints()[0].y));
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

	void Game::SetUp()
	{
		_p._collider.AddPoint(geo::Point(10, 0));
		_p._collider.AddPoint(geo::Point(10, 30));
		_p._collider.AddPoint(geo::Point(40, 0));
		_p._collider.AddPoint(geo::Point(40, 30));
	}

	void Game::RecursiveDisplay(Entity * e)
	{
		if (e->children.size())
		{
			sf::Sprite s = sf::Sprite(textures[e->texture()]);
			s.setPosition(sf::Vector2f(e->_collider._x, e->_collider._y));
			this->_window.draw(s);
			for (Entity child: e->children)
			{
				sf::Sprite s = sf::Sprite(textures[child->texture()]);
				s.setPosition(sf::Vector2f(child->_collider._x, child->_collider._y));
				this->_window.draw(s);
				RecursiveDisplay(&(*child));
			}	
		}
		else
		{
			sf::Sprite s = sf::Sprite(textures[e->texture()]);
			s.setPosition(sf::Vector2f(e->_collider._x, e->_collider._y));
			this->_window.draw(s);
		}
	}

	void Game::Run()
	{
		std::cout<<"Run()"<<std::endl;
		Time __t__();
		Load();
		SetUp();
		_window.create(sf::VideoMode(200, 200), "bruh");
		sf::View view = _window.getDefaultView();
		view.setSize(200, -200); 
		_window.setView(view);
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
			Time::Tick();
			Update();
			Display();
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
					if (e->_collider._isActive)
					{
						for (geo::Point p: entity->_collider.ReturnPoints())
						{
							if (e->_collider.IsIn(p) && !Contains<Entity>((*e->_collider._collidedEntities.begin()).Switch(NULL), (*e->_collider._collidedEntities.end()).Switch(NULL), *entity))
							{
								auto ptr = geo::Pointer<Entity>(*e);
								e->_collider.OnCollisionEnter(ptr);
							}
							else if (e->_collider.IsIn(p) && Contains<Entity>((*e->_collider._collidedEntities.begin()).Switch(NULL), (*e->_collider._collidedEntities.end()).Switch(NULL), *entity))
							{
								auto ptr = geo::Pointer<Entity>(*e);
								e->_collider.OnCollisionStay(ptr);
							}

							else if (Contains<Entity>((*e->_collider._collidedEntities.begin()).Switch(NULL), (*e->_collider._collidedEntities.end()).Switch(NULL), *entity))
							{
								auto ptr = geo::Pointer<Entity>(*e);
								e->_collider.OnCollisionExit(ptr);
							}
						}
					}

					auto mouse = sf::Mouse::getPosition(_window);
					if (!e->children.size())
					{
						if (e.IsIn(geo::Point(mouse.x, mouse.y)))
						{
							e.
						}
					}
					
					if (!e->children.size())
					{
						e->Update();
					}

					else
					{
						e->Update();
						e->UpdateChildren();
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

	
}