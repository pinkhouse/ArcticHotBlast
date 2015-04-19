#pragma once

#include "Item.h"

class Upgrade :
	public Item
{
public:
	Upgrade();
	Upgrade(TypeID typeID, sf::Vector2f position);
	virtual ~Upgrade();

	virtual bool update(sf::Time& frameTime);
	void setTypeID(TypeID typeID);

private:
	virtual void initialize();
};

