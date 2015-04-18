#include "SFML\Graphics.hpp"
#include "Player.h"
#include "Map.h"
#include "CollidersDB.h"
#include "AssetLibrary.h"
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
	AssetLibrary* assetLibrary;
	Player* player;
	sf::RenderWindow* window;
	sf::ContextSettings windowSettings;
	sf::View mainCamera;
	sf::Clock frameClock;
	sf::Time frameTime;
	Map* map;
};

