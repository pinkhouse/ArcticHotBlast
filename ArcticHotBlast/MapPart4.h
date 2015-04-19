#pragma once
#include "MapPartBuilder.h"
class MapPart4 : public MapPartBuilder
{
public:
	void buildPlatforms();
	void buildEnemySpawnSpots();
	void buildItemSpawnSpots();

	MapPart4();
	~MapPart4();
};