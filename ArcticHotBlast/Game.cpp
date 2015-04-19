#include "Game.h"
#include <iostream>

Game::Game()
{
	devMode = true;
	collidersDB = CollidersDB::instance();
	assetLibrary = AssetLibrary::instance();
	assetLibrary->initialize();
	windowSettings.antialiasingLevel = 8;
	window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Arctic Hot Blast", sf::Style::Close, windowSettings);
	//window->setFramerateLimit(500);
	window->setMouseCursorVisible(false);
	mainCamera = new sf::View(sf::FloatRect(0, 0, 1280, 720));
	window->setView(*mainCamera);
	Collider* leftBorder = new Collider(sf::Vector2f(32, 720), sf::Vector2f(-32.0f, 0.0f),
		sf::Vector2f(0.0f, 0.0f));
	CollidersDB::instance()->leftBorder = leftBorder;
	player = new Player(sf::Vector2f(100, 100));
	map = new Map();
	assetLibrary->mainCamera = this->mainCamera;
	assetLibrary->mainWindow = this->window;
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
		if (window->hasFocus())
		{
#pragma region GameLoop
			cursor.update(*window);
			player->update(frameTime, event);
			mainView.update();
			map->update();
		}
#pragma endregion
		window->clear(sf::Color::Magenta);
#pragma region Drawing
		this->window->draw(*map);
		this->window->draw(*player);

		if (devMode)
		{
			collidersDB->draw(*window);
		}
		this->window->draw(cursor);
#pragma endregion
		window->display();
	}
	return true;
}