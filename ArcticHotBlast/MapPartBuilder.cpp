#include "MapPartBuilder.h"


MapPartBuilder::MapPartBuilder()
{
}


MapPartBuilder::~MapPartBuilder()
{
}

void MapPartBuilder::createNewMapPart(float beginPoint)
{
	mapPart = new MapPart();
	buildPlatforms(beginPoint);
}

MapPart* MapPartBuilder::getMapPart()
{
	return mapPart;
}