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
	bool taken;
	int ID;
	inline bool operator==(const Collider &i1)
	{
		return (i1.ID == this->ID);
	}
protected:
	Item();
	sf::Sprite item;
	sf::Texture* textureItem;
	TypeID idType;
	virtual void initialize() = 0;
};

