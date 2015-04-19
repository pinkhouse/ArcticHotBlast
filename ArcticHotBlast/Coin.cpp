#include "Coin.h"

Coin::Coin()
{
	this->textureItem = AssetLibrary::instance()->textureMap;
	this->item.setTexture(*textureItem);
	this->item.setTextureRect(sf::IntRect(128, 32, 160, 64));
	this->idType = TypeID::Coin;

	this->coinAnimation = new Animation(item, 4, 10.0f, sf::Vector2i(128, 32), sf::Vector2i(256, 32));
}

Coin::~Coin()
{
}

bool Coin::update(sf::Time& frameTime)
{
	itemCollider.update(item.getPosition());
	coinAnimation->play(frameTime);
	return false;
}

void Coin::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(item);
}