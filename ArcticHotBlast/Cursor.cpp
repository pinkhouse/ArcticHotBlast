#define _USE_MATH_DEFINES
#include "Cursor.h"
#include <iostream>
#include "CollidersDB.h"
#include <cmath>

Cursor::Cursor()
{
	textureCursor.loadFromFile("data/img/crosshair.png");
	cursor.setTexture(textureCursor);
	cursor.setOrigin(16.0f, 16.0f);
}


Cursor::~Cursor()
{
}

void Cursor::update(sf::RenderWindow& window)
{
	sf::Vector2i mPosition = sf::Mouse::getPosition(window);
	sf::Vector2f worldPos = window.mapPixelToCoords(mPosition);
	cursor.setPosition(worldPos);

	/*float angler = atan2(CollidersDB::instance()->player->getCenter().y - worldPos.y, CollidersDB::instance()->player->getCenter().x - worldPos.x);
	float angle = angler * 180 / M_PI;
	std::cout << angle << std::endl;*/



}

void Cursor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(cursor);
}
