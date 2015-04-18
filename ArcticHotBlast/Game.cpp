#include "Game.h"

Game::Game()
{
	devMode = true;
	collidersDB = CollidersDB::instance();
	windowSettings.antialiasingLevel = 8;
	window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Frankenstein's Rabbit Commando", sf::Style::Close, windowSettings);
	window->setFramerateLimit(200);
	mainCamera = sf::View(sf::FloatRect(0, 0, 1280, 720));
	window->setView(mainCamera);

	player = new Player(sf::Vector2f(100, 100));
	map = new Map();
}

Game::~Game()
{
}

int Game::run()
{
	while (window->isOpen())
	{
		frameTime = frameClock.restart();
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
#pragma region GameLoop
		player->update(frameTime, event);
#pragma endregion
		window->clear(sf::Color::Magenta);
#pragma region Drawing
		window->draw(*player);
		this->window->draw(*map);

		if (devMode)
		{
			collidersDB->draw(*window);
		}
#pragma endregion
		window->display();
	}
	return true;
}