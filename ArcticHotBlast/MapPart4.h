#pragma once
#include "MapPartBuilder.h"
class MapPart4 : public MapPartBuilder
{
public:
	//void createNewMapPart();
	void buildPlatforms(float x);
	void buildEnemySpawnSpots();
	void buildItemSpawnSpots();

	MapPart4();
	~MapPart4();
protected:
	
private:
	void createPlatform(float x, float y, int z);
};

