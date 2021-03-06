#include "Map.h"
#include "CollidersDB.h"
#include "AssetLibrary.h"
#include <iostream>

Map::Map()
{
	textureMap = AssetLibrary::instance()->textureMap;
	addGroundParts(6);
	groundCollider = new Collider(sf::Vector2f(1280.0f, 32.0f), sf::Vector2f(0.0f, 690.0f), sf::Vector2f(0.0f, 0.0f));
	CollidersDB::ground = groundCollider;
	generateMap(3);
	offScreenCleared[0] = false;
	offScreenCleared[1] = false;
	pinguin = new Pinguin(sf::Vector2f(300, 6));
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
	target.draw(*pinguin);
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

void Map::update(sf::Time& frameTime)
{

	scrollGround();
	clearOffScreen();
	for (MapPart* mapPart : mapParts)
	{
		mapPart->update(frameTime);
	}
	pinguin->update(frameTime);
}

void Map::addMapPart(MapPartBuilder* mapPartBuilder, float startingPoint)
{
	mapPartBuilder->createNewMapPart(startingPoint);
	MapPart* mapPart = mapPartBuilder->getMapPart();
	mapParts.push_back(mapPart);
}

void Map::clearOffScreen()
{
	if (!offScreenCleared[0] && CollidersDB::instance()->player->getPosition().x > 6000 && mapParts.front()->startPoint < 5000)
	{
		mapParts.front()->~MapPart();
		mapParts.erase(mapParts.begin());
		offScreenCleared[0] = true;
	}
	else
	{
		if (!offScreenCleared[1] && CollidersDB::instance()->player->getPosition().x > 11000 && mapParts.front()->startPoint < 10000)
		{
			mapParts.front()->~MapPart();
			mapParts.erase(mapParts.begin());
			offScreenCleared[1] = true;
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
		int partID = std::rand() % 2;
		switch (partID)
		{
		case 0:
			addMapPart(new MapPart1(), i * 5000.0f);
			break;
		case 1:
			addMapPart(new MapPart2(), i * 5000.0f);
			break;
		default:
			break;
		}
	}
}