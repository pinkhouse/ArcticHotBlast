#pragma once

#include "Item.h"
#include "Animation.h"

class Coin :
	public Item
{
public:
	Coin();
	virtual ~Coin();

	virtual bool update(sf::Time& frameTime);

private:
	Animation* coinAnimation;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

