#include "MapPart.h"


MapPart::MapPart()
{
}


MapPart::~MapPart()
{
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