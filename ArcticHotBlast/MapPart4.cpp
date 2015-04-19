#include "MapPart4.h"
#include "Platform.h"

MapPart4::MapPart4()
{
}


MapPart4::~MapPart4()
{
}

void MapPart4::buildPlatforms(float beginPoint)
{
	this->beginPoint = beginPoint;
	/*createPlatform(250, 540, 8);
	createPlatform(500, 392, 7);
	createPlatform(800, 392, 6);
	createPlatform(850, 244, 10);
	createPlatform(700, 540, 15);*/
}

void MapPart4::createPlatform(float xx, float yy, int zz)
{
	Platform* platform = new Platform(sf::Vector2f(beginPoint + xx, yy), zz);
	mapPart->addPlatform(platform);
}