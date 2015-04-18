#include "Game.h"
#include <iostream>

Game::Game()
{
	devMode = true;
	collidersDB = CollidersDB::instance();
	assetLibrary = AssetLibrary::instance();
	assetLibrary->initialize();
	assetLibrary->mainCamera = &this->mainCamera;
	assetLibrary->mainWindow = this->window;
	windowSettings.antialiasingLevel = 8;
	window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Frankenstein's Rabbit Commando", sf::Style::Close, windowSettings);
	window->setFramerateLimit(500);
	mainCamera = sf::View(sf::FloatRect(0, 0, 1280, 720));
	window->setView(mainCamera);

	player = new Player(sf::Vector2f(100, 100));
	map = new Map();
	//std::cout << mainCamera.getViewport().left;
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
		this->window->draw(*map);
		this->window->draw(*player);

		if (devMode)
		{
			collidersDB->draw(*window);
		}
#pragma endregion
		window->display();
	}
	return true;
}
