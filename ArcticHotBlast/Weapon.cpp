#define _USE_MATH_DEFINES
#include <cmath>
#include "Weapon.h"
#include "AssetLibrary.h"
#include "CollidersDB.h"

Weapon::Weapon(sf::Vector2f hookPoint)
{
	this->textureWeapon = AssetLibrary::instance()->textureWeapon;
	weapon.setTexture(*textureWeapon);

	weapon.setOrigin(5, 14);
	weapon.setPosition(hookPoint);
	this->armLocation = sf::Vector2f(armLocation.x - weapon.getPosition().x, armLocation.y - weapon.getPosition().y);
	armRotated = false;
	armRotation = 0;
}
Weapon::~Weapon()
{
}

Weapon::Weapon()
{
}

bool Weapon::update(sf::Vector2f hookPoint, sf::Event& event)
{
	checkInput(event);
	this->weapon.setPosition(hookPoint.x, hookPoint.y);

	sf::Vector2i mPosition = sf::Mouse::getPosition(*AssetLibrary::instance()->mainWindow);
	sf::Vector2f worldPos = AssetLibrary::instance()->mainWindow->mapPixelToCoords(mPosition);
	float angler = atan2(CollidersDB::instance()->player->getCenter().y - worldPos.y, CollidersDB::instance()->player->getCenter().x - worldPos.x);
	float angle = (angler * 180 / M_PI) + 180.0f;
	this->weapon.setRotation(angle);
	if (angle > 90 && angle< 270)
	{
		weapon.setScale(1, -1);
		return false;
	}
	else
	{
		weapon.setScale(1, 1);
		return true;
	}
}

void Weapon::checkInput(sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//shoot
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
