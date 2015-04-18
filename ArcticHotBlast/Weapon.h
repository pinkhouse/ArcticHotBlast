#pragma once

#include "SFML\Graphics.hpp"
#include "AssetLibrary.h"

class Weapon:
	public sf::Drawable 
{
public:
	Weapon();
	~Weapon();

	bool update(sf::Vector2f playerPosition, sf::Event& event);
	void setPosition(sf::Vector2f armLocation);
	void setPosition(float positionX, float positionY);
	sf::Vector2f getPosition();
private:
	sf::Sprite weapon;
	sf::Texture* textureWeapon;

	sf::Vector2f armLocation;
	int armRotation;
	bool armRotated;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void checkInput(sf::Event& event);


};

