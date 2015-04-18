#pragma once
#include "MapPart.h"
class MapPartBuilder
{
public:
	MapPartBuilder();
	~MapPartBuilder();
	MapPart getMapPart();

	virtual void buildPlatforms() = 0;
	virtual void buildEnemySpawnSpots() = 0;
	virtual void buildItemSpawnSpots() = 0;
protected:
	MapPart mapPart;
};