#pragma once
#include "MapPartBuilder.h"
class MapPart2 : public MapPartBuilder
{
public:
	void buildPlatforms();
	void buildEnemySpawnSpots();
	void buildItemSpawnSpots();

	MapPart2();
	~MapPart2();
};
