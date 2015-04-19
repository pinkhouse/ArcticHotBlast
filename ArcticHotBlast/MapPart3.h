#pragma once
#include "MapPartBuilder.h"
class MapPart3 : public MapPartBuilder
{
public:
	void buildPlatforms();
	void buildEnemySpawnSpots();
	void buildItemSpawnSpots();

	MapPart3();
	~MapPart3();
};
