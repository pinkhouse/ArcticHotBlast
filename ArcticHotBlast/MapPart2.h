#pragma once
#include "MapPartBuilder.h"
class MapPart2 : public MapPartBuilder
{
public:
	//void createNewMapPart();
	void buildPlatforms(float x);
	void buildEnemySpawnSpots();
	void buildItemSpawnSpots();

	MapPart2();
	~MapPart2();
protected:
	
private:
	void createPlatform(float x, float y, int z);
};

