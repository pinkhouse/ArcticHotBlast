#pragma once
#include "AssetLibrary.h"
#include "Collider.h"

enum class TypeID
{
	Coin,
	Dyfuser,
	EnginePart,
	Baterry
};

class Item :
	public sf::Drawable
{
public:
	virtual ~Item();
	virtual bool update() = 0;

protected:
	Item();
	sf::Sprite item;
	Collider itemCollider;
	sf::Texture* textureItem;
	TypeID idType;
};

