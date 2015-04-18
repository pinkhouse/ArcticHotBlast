#include "SFML\Graphics.hpp"
#include "Player.h"
#include "Map.h"
#include "CollidersDB.h"
#pragma once
class Game
{
public:
	Game();
	virtual ~Game();
	int run();

private:
	bool devMode;
	CollidersDB* collidersDB;
	Player* player;
	sf::RenderWindow* window;
	sf::ContextSettings windowSettings;
	sf::View mainCamera;
	sf::Clock frameClock;
	sf::Time frameTime;
	Map* map;
};

