#include "Coin.h"

Coin::Coin()
{
	this->textureItem = AssetLibrary::instance()->textureMap;
	this->item.setTextureRect(sf::IntRect(128, 32, 160, 64));
}


Coin::~Coin()
{
}


bool Coin::update()
{
	itemCollider.update(item.getPosition());
	return false;
}

void Coin::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(item);
}