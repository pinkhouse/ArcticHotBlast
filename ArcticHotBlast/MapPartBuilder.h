#pragma once
#include "MapPart.h"
class MapPartBuilder
{
public:
	virtual void createNewMapPart( float x);
	~MapPartBuilder();
	MapPart* getMapPart();
	MapPartBuilder();
	virtual void buildPlatforms() = 0;
	//virtual void buildEnemySpawnSpots() = 0;
	virtual void buildItemSpawnSpots() = 0;
	virtual void buildItems();
protected:
	float beginPoint;
	MapPart* mapPart;
	std::vector<sf::Vector2f*> spawnSpots;
	virtual void createItemSpawnSpot(float x, float y);
	virtual void createPlatform(float x, float y, int z);
};