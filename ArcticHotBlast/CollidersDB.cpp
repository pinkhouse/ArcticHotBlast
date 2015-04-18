#include "CollidersDB.h"


CollidersDB* CollidersDB::_instance = 0;
Collider* CollidersDB::player = 0;
Collider* CollidersDB::ground = 0;
std::vector<Collider*>* CollidersDB::obstacles = new std::vector<Collider*>;
std::vector<Collider*>* CollidersDB::items = new std::vector<Collider*>;
std::vector<Collider*>* CollidersDB::buttons = new std::vector<Collider*>;
sf::RenderWindow* CollidersDB::gWindow = 0;

CollidersDB::CollidersDB()
{
}

CollidersDB* CollidersDB::instance()
{
	if (_instance == 0)
	{
		_instance = new CollidersDB();
	}
	return _instance;
}

void CollidersDB::draw(sf::RenderWindow& window)
{
	if (player != 0)
	{
		window.draw(*player);
	}
	if (ground != 0)
	{
		window.draw(*ground);
	}

	if (obstacles->size() > 0)
	{
		for (Collider* obstacle : *obstacles)
		{
			window.draw(*obstacle);
		}
	}
	if (items->size() > 0)
	{
		for (Collider* point : *items)
		{
			window.draw(*point);
		}
	}
	if (buttons->size() > 0)
	{
		for (Collider* button : *buttons)
		{
			window.draw(*button);
		}
	}
}

void CollidersDB::clearDb()
{
	delete player;
	delete ground;
	delete obstacles;
	delete items;
	delete buttons;
	player = 0;
	ground = 0;
	obstacles = new std::vector<Collider*>;
	items = new std::vector<Collider*>;
	buttons = new std::vector<Collider*>;
}