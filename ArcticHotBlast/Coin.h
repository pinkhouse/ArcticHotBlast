#pragma once

#include "Item.h"
#include "Animation.h"

class Coin :
	public Item
{
public:
	Coin();
	Coin(sf::Vector2f position);
	virtual ~Coin();

	virtual bool update(sf::Time& frameTime);

private:
	Animation* coinAnimation;
	virtual void initialize();
};

