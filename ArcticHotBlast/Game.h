#include "SFML\Graphics.hpp"
#pragma once
class Game
{
public:
	Game();
	virtual ~Game();
	int run();

private:
	sf::RenderWindow* window;
	sf::ContextSettings windowSettings;
	sf::View mainCamera;
	sf::Clock frameClock;
	sf::Time frameTime;
};

