#include "MapPart1.h"
#include "Platform.h"

MapPart1::MapPart1()
{
}


MapPart1::~MapPart1()
{
}

void MapPart1::buildPlatforms(float x)
{
	Platform* platform = new Platform(sf::Vector2f(x + 500.0f, 528.0f), 4);
	mapPart->addPlatform(platform);

	platform = new Platform(sf::Vector2f(x + 750.0f, 368.0f), 10);
	mapPart->addPlatform(platform);
}

