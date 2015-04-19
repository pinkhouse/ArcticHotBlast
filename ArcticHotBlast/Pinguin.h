#pragma once
#include "Enemy.h"
#include <iostream>


class Pinguin :
	public Enemy
{
public:
	Pinguin();
	Pinguin(sf::Vector2f position);
	virtual  ~Pinguin();

	virtual bool update(sf::Time& frameTime);
	virtual void attack();

private:
	virtual void move();
	virtual void potentialEnergy(sf::Time& frameTime);
	void jump();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Sprite pinguin;
	sf::Texture* texturePinguin;

	Collider* standingOn;
	std::vector<Collider*>platformsToCheck;
	sf::Time* frameTime;
	virtual void checkPlatformsCollision();
};

