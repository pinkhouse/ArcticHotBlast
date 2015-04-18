#include "Map.h"
#include "CollidersDB.h"
#include "AssetLibrary.h"

Map::Map()
{
	textureMap = AssetLibrary::instance()->textureMap;
	addGroundParts(5);
	groundCollider = new Collider(sf::Vector2f(1280.0f, 32.0f), sf::Vector2f(0.0f, 688.0f), sf::Vector2f(0.0f, 0.0f));
	CollidersDB::ground = groundCollider;
}


Map::~Map()
{
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (sf::Sprite groundPart : groundParts)
	{
		target.draw(groundPart);
	}
}

void Map::addGroundParts(int howMany)
{
	for (int i = 0; i < howMany; i++)
	{
	sf::Sprite groundPart;
		groundPart.setTexture(*textureMap);
		groundPart.setTextureRect(sf::IntRect(0, 0, 256, 32));
		groundPart.setPosition(sf::Vector2f(256.0f * i, 688.0f));
		groundParts.push_back(groundPart);
	}
}