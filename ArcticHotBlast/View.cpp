#include "View.h"
#include <iostream>

View::View()
{
	scene = 0;
}


View::~View()
{
}

void View::update()
{
	AssetLibrary::instance()->mainWindow->setView(*AssetLibrary::instance()->mainCamera);
	CollidersDB::instance()->leftBorder->update(sf::Vector2f(AssetLibrary::instance()->mainCamera->getCenter().x
		- AssetLibrary::instance()->mainCamera->getSize().x / 2 - 32, 0.0f));

	CollidersDB::instance()->ground->update(sf::Vector2f(CollidersDB::instance()->leftBorder->getPosition().x + 32.0f,
		AssetLibrary::instance()->mainWindow->getSize().y-32));
	

	float moveBorder = AssetLibrary::instance()->mainCamera->getCenter().x + 100;

		if (CollidersDB::instance()->player->getPosition().x > moveBorder)		
		{
			cameraOffset = CollidersDB::instance()->player->getPosition().x - moveBorder;
			while (cameraOffset > 1.0f)
			{ 
				--cameraOffset;
				AssetLibrary::instance()->mainCamera->move(1, 0);
			}
		}

}