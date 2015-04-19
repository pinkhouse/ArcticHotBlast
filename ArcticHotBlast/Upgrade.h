#pragma once

#include "Item.h"

class Upgrade :
	public Item
{
public:
	Upgrade();
	Upgrade(TypeID typeID);
	virtual ~Upgrade();

	virtual bool update();
	void setTypeID(TypeID typeID);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

