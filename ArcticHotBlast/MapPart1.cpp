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
	this->beginPoint = beginPoint;
	createPlatform(100, 540, 5);
}

void MapPart1::createPlatform(float xx, float yy, int zz)
{
	Platform* platform = new Platform(sf::Vector2f(beginPoint + xx, yy), zz);
	mapPart->addPlatform(platform);
}