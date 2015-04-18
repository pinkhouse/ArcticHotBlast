#include "Game.h"

Game::Game()
{
	windowSettings.antialiasingLevel = 8;
	window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Frankenstein's Rabbit Commando", sf::Style::Close, windowSettings);
	window->setFramerateLimit(200);
	mainCamera = sf::View(sf::FloatRect(0, 0, 1280, 720));
	window->setView(mainCamera);

	player = new Player(sf::Vector2f(100, 100));
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
		
#pragma endregion
		window->clear(sf::Color::White);
#pragma region Drawing
		window->draw(*player);
#pragma endregion
		window->display();
	}
	return true;
}
