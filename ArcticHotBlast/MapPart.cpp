#include "MapPart.h"
#include <iostream>

MapPart::MapPart()
{
}


MapPart::~MapPart()
{
	for each (Platform *platform in platforms)
	{
		delete platform;
	}
	platforms.erase(platforms.begin(), platforms.end());
	platforms.clear();
}

void MapPart::addPlatform(Platform* platform)
{
	this->platforms.push_back(platform);
}

//void MapPart::addEnemySpawnSpot(sf::Vector2f* enemySpawnSpot)
//{
//	enemySpawnSpots.push_back(enemySpawnSpot);
//}
//
void MapPart::addItem(Item* item)
{
	items.push_back(item);
}

std::vector<Platform*> MapPart::getPlatforms()
{
	return platforms;
}

void MapPart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(Platform* platform : platforms)
	{
		platform->draw(target, states);
	}
	for (Item* item : items)
	{
		item->draw(target, states);
	}
}

void MapPart::update(sf::Time& frameTime)
{
	for (Item* item : items)
	{
		item->update(frameTime);
	}
}