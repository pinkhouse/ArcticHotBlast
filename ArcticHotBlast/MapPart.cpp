#include "MapPart.h"


MapPart::MapPart()
{
}


MapPart::~MapPart()
{
}

void MapPart::addPlatform(sf::Sprite* platform)
{
	this->platforms->push_back(platform);
}

void MapPart::addEnemySpawnSpot(sf::Vector2f* enemySpawnSpot)
{
	enemySpawnSpots->push_back(enemySpawnSpot);
}

void MapPart::addItemSpawnSpot(sf::Vector2f* itemSpawnSpot)
{
	itemSpawnSpots->push_back(itemSpawnSpot);
}