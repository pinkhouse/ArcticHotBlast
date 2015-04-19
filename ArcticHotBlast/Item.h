#pragma once
#include "AssetLibrary.h"
#include "Collider.h"

enum class TypeID
{
	Coin,
	Dyfuser,
	EnginePart,
	Battery
};

class Item :
	public sf::Drawable
{
public:
	virtual ~Item();
	virtual bool update(sf::Time& frameTime) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	Collider* collider;
protected:
	Item();
	sf::Sprite item;
	sf::Texture* textureItem;
	TypeID idType;
	virtual void initialize() = 0;
};

