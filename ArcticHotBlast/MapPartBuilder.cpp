#include "MapPartBuilder.h"
#include "Coin.h"
#include "Upgrade.h"


MapPartBuilder::MapPartBuilder()
{
}


MapPartBuilder::~MapPartBuilder()
{
}

void MapPartBuilder::createNewMapPart(float beginPoint)
{
	mapPart = new MapPart();
	this->beginPoint = beginPoint;
	buildPlatforms();
	buildItems();
}

MapPart* MapPartBuilder::getMapPart()
{
	return mapPart;
}

void MapPartBuilder::buildItems()
{
	buildItemSpawnSpots();
	if (spawnSpots.size() > 0)
	{
		for (sf::Vector2f* spot : spawnSpots)
		{
			Item* item;
			int randomItem = rand() % 500;

			if (randomItem >= 0 && randomItem <= 490)
			{
				item = new Coin(*spot);
			}
			else
			{
				if (randomItem >= 491 && randomItem <= 493)
				{
					item = new Upgrade(TypeID::Battery, *spot);
				}
				else
				{
					if (randomItem >= 494 && randomItem <= 496)
					{
						item = new Upgrade(TypeID::Dyfuser, *spot);
					}
					else
					{
						if (randomItem >= 497 && randomItem <= 499)
						{
							item = new Upgrade(TypeID::EnginePart, *spot);
						}
						else
						{
							item = new Coin(sf::Vector2f(0, 0));
						}
					}
				}
			}
			mapPart->addItem(item);
		}
	}
}

void MapPartBuilder::createPlatform(float x, float y, int z)
{
	Platform* platform = new Platform(sf::Vector2f(beginPoint + x, y), z);
	mapPart->addPlatform(platform);
}

void MapPartBuilder::createItemSpawnSpot(float x, float y)
{
	sf::Vector2f* spot = new sf::Vector2f(beginPoint + x, y);
	spawnSpots.push_back(spot);
}