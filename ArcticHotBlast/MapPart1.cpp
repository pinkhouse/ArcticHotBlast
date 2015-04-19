#include "MapPart1.h"
#include "Platform.h"

MapPart1::MapPart1()
{
}


MapPart1::~MapPart1()
{
}

void MapPart1::buildPlatforms(float beginPoint)
{
	mapPart->startPoint = beginPoint;
	this->beginPoint = beginPoint;
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

void MapPart1::createPlatform(float xx, float yy, int zz)
{
	Platform* platform = new Platform(sf::Vector2f(beginPoint + xx, yy), zz);
	mapPart->addPlatform(platform);
}