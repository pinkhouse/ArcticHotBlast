#include "Pinguin.h"

Pinguin::Pinguin()
{
	this->texturePinguin = AssetLibrary::instance()->texturePinguin;
	this->pinguin.setTexture(*texturePinguin);
	this->pinguin.setTextureRect(sf::IntRect(0, 0, 64, 96));
	pinguin.setOrigin(32, 96);
}

Pinguin::Pinguin(sf::Vector2f position)
{

	this->texturePinguin = AssetLibrary::instance()->texturePinguin;
	this->pinguin.setTexture(*texturePinguin);
	this->pinguin.setTextureRect(sf::IntRect(0, 0, 64, 96));
	pinguin.setOrigin(32, 96);
	pinguin.setPosition(position);
}


Pinguin::~Pinguin()
{
}

bool Pinguin::update(sf::Time& frameTime)
{
	return false;
}

void Pinguin::attack()
{

}

void Pinguin::move()
{

}

void Pinguin::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(pinguin);
}
