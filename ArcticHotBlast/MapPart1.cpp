#include "MapPart1.h"
#include "Platform.h"
#include "Coin.h"
#include "Upgrade.h"
#include <iostream>

MapPart1::MapPart1()
{
}


MapPart1::~MapPart1()
{
}

void MapPart1::buildPlatforms()
{
	createPlatform(250, 540, 8);
	createPlatform(450, 392, 7);
	createPlatform(800, 392, 6);
	createPlatform(850, 244, 10);
	createPlatform(700, 540, 15);
	createPlatform(1300, 244, 7);
	createPlatform(1250, 392, 4);
	createPlatform(1500, 540, 7);
	createPlatform(2050, 540, 7);
	createPlatform(2480, 392, 3);
	createPlatform(2680, 244, 8);
	createPlatform(3020, 540, 6);
	createPlatform(3400, 392, 8);
	createPlatform(3600, 540, 5);
	createPlatform(3760, 244, 2);
	createPlatform(4000, 392, 7);
	createPlatform(4300, 540, 8);
	createPlatform(4450, 244, 10);
	createPlatform(4872, 392, 4);
}

void MapPart1::buildEnemySpawnSpots()
{

}

void MapPart1::buildItemSpawnSpots()
{
	createItemSpawnSpot(250.0f, 505.0f);
	createItemSpawnSpot(300.0f, 505.0f);
	createItemSpawnSpot(350.0f, 505.0f);
	createItemSpawnSpot(400.0f, 505.0f);
}
