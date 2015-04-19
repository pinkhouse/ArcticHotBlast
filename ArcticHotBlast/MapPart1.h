#pragma once
#include "MapPartBuilder.h"
class MapPart1 : public MapPartBuilder
{
public:
	//void createNewMapPart();
	void buildPlatforms(float x);
	void buildEnemySpawnSpots();
	void buildItemSpawnSpots();

	MapPart1();
	~MapPart1();
protected:
	
private:
	void createPlatform(float x, float y, int z);
};

