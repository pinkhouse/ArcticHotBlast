#pragma once
#include "MapPartBuilder.h"
class MapPart1 : public MapPartBuilder
{
public:
	void buildPlatforms();
	void buildEnemySpawnSpots();
	void buildItemSpawnSpots();

	MapPart1();
	~MapPart1();
};

