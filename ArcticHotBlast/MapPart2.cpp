#include "MapPart2.h"
#include "Platform.h"

MapPart2::MapPart2()
{
}


MapPart2::~MapPart2()
{
}

void MapPart2::buildPlatforms(float beginPoint)
{
	this->beginPoint = beginPoint;
	createPlatform(150, 540, 10);
	createPlatform(750, 392, 7);
	createPlatform(900, 244, 6);
	createPlatform(350, 244, 10);
	createPlatform(700, 540, 15);
	createPlatform(1280, 244, 15);
	createPlatform(1880, 392, 8);
	createPlatform(2350, 540, 4);
	createPlatform(2600, 392, 6);
	createPlatform(2800, 540, 15);
	createPlatform(3000, 244, 4);
	createPlatform(3350, 392, 5);
	createPlatform(3750, 540, 5);
	createPlatform(4050, 392, 9);
	createPlatform(4480, 244, 8);
}

void MapPart2::createPlatform(float xx, float yy, int zz)
{
	Platform* platform = new Platform(sf::Vector2f(beginPoint + xx, yy), zz);
	mapPart->addPlatform(platform);
}