#include "MapPart3.h"
#include "Platform.h"
#include "Coin.h"

MapPart3::MapPart3()
{
}


MapPart3::~MapPart3()
{
}

void MapPart3::buildPlatforms()
{
	/*createPlatform(250, 540, 8);
	createPlatform(500, 392, 7);
	createPlatform(800, 392, 6);
	createPlatform(850, 244, 10);
	createPlatform(700, 540, 15);*/
}

void MapPart3::buildEnemySpawnSpots()
{

}

void MapPart3::buildItemSpawnSpots()
{
	createItemSpawnSpot(250.0f, 508);
}
