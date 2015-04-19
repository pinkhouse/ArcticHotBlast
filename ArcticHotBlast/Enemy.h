#pragma once

#include "AssetLibrary.h"
#include "Animation.h"
#include "CollidersDB.h"

class Enemy :
	public sf::Drawable
{
public:
	virtual ~Enemy();

	virtual bool update(sf::Time& frametime) = 0;
	virtual void attack() = 0;

protected:
	virtual void potentialEnergy(sf::Time& frameTime) = 0;
	virtual void checkPlatformsCollision() = 0;
	virtual void move() = 0;


	bool isAlive;
	bool facingRight;
	unsigned int enemyID;

	Collider* enemyCollider;
	
	float fallingSpeed;
	float gravity;
	float walkSpeed;
	float currentSpeed;
	bool isGrounded;

};

