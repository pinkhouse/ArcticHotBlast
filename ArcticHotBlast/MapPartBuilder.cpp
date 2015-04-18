#include "MapPartBuilder.h"


MapPartBuilder::MapPartBuilder()
{
}


MapPartBuilder::~MapPartBuilder()
{
}

void MapPartBuilder::createNewMapPart(float x)
{
	mapPart = new MapPart();
	buildPlatforms(x);
}

MapPart* MapPartBuilder::getMapPart()
{
	return mapPart;
}