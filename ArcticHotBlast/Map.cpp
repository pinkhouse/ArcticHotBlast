#include "Map.h"
#include "CollidersDB.h"
#include "AssetLibrary.h"
#include <iostream>

Map::Map()
{
	textureMap = AssetLibrary::instance()->textureMap;
	addGroundParts(6);
	groundCollider = new Collider(sf::Vector2f(1280.0f, 32.0f), sf::Vector2f(0.0f, 688.0f), sf::Vector2f(0.0f, 0.0f));
	CollidersDB::ground = groundCollider;
	generateMap(3);
}

Map::~Map()
{
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (sf::Sprite groundPart : groundParts)
	{
		target.draw(groundPart);
	}
	for (MapPart* mapPart : mapParts)
	{
		mapPart->draw(target, states);
	}
}

void Map::addGroundParts(int howMany)
{
	for (int i = 0; i < howMany; i++)
	{
	sf::Sprite groundPart;
		groundPart.setTexture(*textureMap);
		groundPart.setTextureRect(sf::IntRect(0, 0, 256, 32));
		groundPart.setPosition(sf::Vector2f(256.0f * i, 688.0f));
		groundParts.push_back(groundPart);
	}
}

void Map::update()
{
	scrollGround();
	clearOffScreen();

}

void Map::addMapPart(MapPartBuilder* mapPartBuilder, float startingPoint)
{
	mapPartBuilder->createNewMapPart(startingPoint);
	MapPart* mapPart = mapPartBuilder->getMapPart();
	mapParts.push_back(mapPart);
}

void Map::clearOffScreen()
{
	if (CollidersDB::instance()->player->getPosition().x > 6000 && mapParts.front()->startPoint < 5000)
	{
		mapParts.front()->~MapPart();
		mapParts.erase(mapParts.begin());
	}
	else
	{
		if (CollidersDB::instance()->player->getPosition().x > 11000 && mapParts.front()->startPoint < 10000)
		{
			mapParts.front()->~MapPart();
			mapParts.erase(mapParts.begin());
		}
	}
}

void Map::scrollGround()
{
	if (groundParts.front().getPosition().x < (AssetLibrary::instance()->mainCamera->getCenter().x - AssetLibrary::instance()->mainCamera->getSize().x / 2 - 256))
	{
		groundParts.front().setPosition(groundParts.back().getPosition().x + 256, groundParts.front().getPosition().y);
		sf::Sprite* tempSprite = &groundParts.front();
		groundParts.pop_front();
		groundParts.push_back(*tempSprite);
	}
}

void Map::generateMap(int numberOfParts)
{
	for (int i = 0; i < numberOfParts; i++)
	{
		int partID = std::rand() % 1;
		switch (partID)
		{
		case 0:
			addMapPart(new MapPart1(), i * 500.0f);
		default:
			break;
		}
	}
}