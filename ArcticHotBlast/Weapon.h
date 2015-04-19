#pragma once

#include "SFML\Graphics.hpp"
#include "AssetLibrary.h"

class Weapon:
	public sf::Drawable 
{
public:
	Weapon(sf::Vector2f hookPoint);
	~Weapon();

	bool update(sf::Vector2f hookPoint, sf::Event& event);
	sf::Vector2f getPosition();

	Weapon();
private:
	sf::Sprite weapon;
	sf::Texture* textureWeapon;
	int armRotation;
	bool armRotated;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void checkInput(sf::Event& event);


};

