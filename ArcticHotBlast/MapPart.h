#pragma once
#include "SFML\Graphics.hpp"
#include <vector>
#include "Platform.h"

class MapPart
{
public:
	MapPart();
	~MapPart();
	void addPlatform(Platform* platform);
	//void addEnemySpawnSpot(sf::Vector2f* enemySpawnSpot);
	//void addItemSpawnSpot(sf::Vector2f* itemSpawnSpot);

	std::vector<Platform*> getPlatforms();
private:
	std::vector<Platform*> platforms;
	//std::vector<sf::Vector2f*> enemySpawnSpots;
	//std::vector<sf::Vector2f*> itemSpawnSpots;
};

