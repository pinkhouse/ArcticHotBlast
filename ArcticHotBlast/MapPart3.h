#pragma once
#include "MapPartBuilder.h"
class MapPart3 : public MapPartBuilder
{
public:
	//void createNewMapPart();
	void buildPlatforms(float x);
	void buildEnemySpawnSpots();
	void buildItemSpawnSpots();

	MapPart3();
	~MapPart3();
protected:
	
private:
	void createPlatform(float x, float y, int z);
};

