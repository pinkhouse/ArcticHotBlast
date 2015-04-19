#include "MapPart.h"
#include <iostream>
#include <algorithm>

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
	for each (Item *item in items)
	{
		delete item;
	}
	items.erase(items.begin(), items.end());
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

std::vector<Item*> MapPart::getItems()
{
	return items;
}

std::vector<Item*> getItems();

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
	Item* itemToDelete = 0;
	for (Item* item : items)
	{
		if (item->update(frameTime))
		{
			itemToDelete = item;
		}
	}
	
	if (itemToDelete != 0)
	{
		delete itemToDelete;
		items.erase(std::remove(items.begin(), items.end(), itemToDelete), items.end());
	}
}