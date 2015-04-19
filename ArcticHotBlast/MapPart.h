#pragma once
#include "SFML\Graphics.hpp"
#include <vector>
#include "Platform.h"
#include "Item.h"
class MapPart
{
public:
	MapPart();
	~MapPart();
	void addPlatform(Platform* platform);
	//void addEnemySpawnSpot(sf::Vector2f* enemySpawnSpot);
	void addItem(Item* item);

	std::vector<Platform*> getPlatforms();
private:
	std::vector<Platform*> platforms;
	//std::vector<sf::Vector2f*> enemySpawnSpots;
	std::vector<Item*> items;
};

