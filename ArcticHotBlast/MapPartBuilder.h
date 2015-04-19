#pragma once
#include "MapPart.h"
class MapPartBuilder
{
public:
	virtual void createNewMapPart( float x);
	~MapPartBuilder();
	MapPart* getMapPart();
	MapPartBuilder();
	virtual void buildPlatforms(float beginPoint) = 0;
	//virtual void buildEnemySpawnSpots() = 0;
	//virtual void buildItemSpawnSpots() = 0;
protected:
	float beginPoint;
	MapPart* mapPart;
};