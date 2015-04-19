#include "MapPart4.h"
#include "Platform.h"
#include "Coin.h"

MapPart4::MapPart4()
{
}


MapPart4::~MapPart4()
{
}

void MapPart4::buildPlatforms()
{
	/*createPlatform(250, 540, 8);
	createPlatform(500, 392, 7);
	createPlatform(800, 392, 6);
	createPlatform(850, 244, 10);
	createPlatform(700, 540, 15);*/
}

void MapPart4::buildEnemySpawnSpots()
{

}

void MapPart4::buildItemSpawnSpots()
{
	createItemSpawnSpot(250.0f, 508);
}