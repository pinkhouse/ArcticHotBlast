#pragma once

#include "CollidersDB.h"
#include "AssetLibrary.h"
#include "Animation.h"

class Enemy :
	public sf::Drawable
{
public:
	virtual ~Enemy();

	virtual bool update(sf::Time& frametime) =0;
	virtual void attack() =0;

protected:
	bool isAlive;
	virtual void move() =0;
	Collider enemyCollider;
};

