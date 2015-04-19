#pragma once

#include "AssetLibrary.h"
#include "CollidersDB.h"

class SnowBall:
	public sf::Drawable
{
public:
	SnowBall();
	~SnowBall();

	bool update(sf::Time& frameTaime);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Sprite snowBall;
	bool isAlive;

};

