#include "SFML\Graphics.hpp"
#include "Player.h"
#pragma once
class Game
{
public:
	Game();
	virtual ~Game();
	int run();

private:
	Player* player;
	sf::RenderWindow* window;
	sf::ContextSettings windowSettings;
	sf::View mainCamera;
	sf::Clock frameClock;
	sf::Time frameTime;
};

