#include "Weapon.h"

#include <iostream>

Weapon::Weapon()
{
	this->textureWeapon = AssetLibrary::instance()->textureWeapon;
	weapon.setTexture(*textureWeapon);

	weapon.setOrigin(5, 22);
	weapon.setPosition(armLocation.x, armLocation.y + 75);
	this->armLocation = sf::Vector2f(armLocation.x - weapon.getPosition().x, armLocation.y - weapon.getPosition().y);
	std::cout << weapon.getPosition().x << " " << weapon.getPosition().y << "\n";
	armRotated = false;
	armRotation = 0;
}
Weapon::~Weapon()
{
}

bool Weapon::update(sf::Vector2f playerPosition, sf::Event& event)
{
	checkInput(event);
	this->weapon.setPosition(playerPosition.x + armLocation.x, playerPosition.y + armLocation.y);
	this->weapon.setRotation(static_cast<float>(armRotation));
	return false;
}

void Weapon::setPosition(sf::Vector2f armLocation)
{
	weapon.setPosition(armLocation);
}

void  Weapon::setPosition(float positionX, float positionY)
{
	weapon.setPosition(positionX, positionY);
}

void Weapon::checkInput(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up && !armRotated)
	{
		armRotated = true;
		if (armRotation > -215)
			armRotation -= 45;
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
	{
		armRotated = false;
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down && !armRotated)
	{
		armRotated = true;
		if (armRotation < 45)
			armRotation += 45;
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down)
	{
		armRotated = false;
	}
}

sf::Vector2f Weapon::getPosition()
{
	return weapon.getPosition();
}
void Weapon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(weapon);
}
