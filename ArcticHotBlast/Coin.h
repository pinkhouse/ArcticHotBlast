#pragma once

#include "Item.h"

class Coin :
	public Item
{
public:
	Coin();
	virtual ~Coin();

	virtual bool update();

private:
	virtual void Coin::draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

