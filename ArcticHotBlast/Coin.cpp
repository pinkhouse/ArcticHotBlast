#include "Coin.h"
#include "CollidersDB.h"

Coin::Coin()
{
	this->initialize();
}

Coin::Coin(sf::Vector2f position)
{
	initialize();
	item.setPosition(position);
	CollidersDB::instance()->items->push_back(this);
}

void Coin::initialize()
{
	this->textureItem = AssetLibrary::instance()->textureMap;
	this->item.setTexture(*textureItem);
	this->item.setTextureRect(sf::IntRect(128, 32, 32, 32));
	this->idType = TypeID::Coin;
	this->coinAnimation = new Animation(item, 4, 7.0f, sf::Vector2i(128, 32), sf::Vector2i(32, 32));
	this->collider = new Collider(sf::Vector2f(32.0f, 32.0f), item.getPosition(), sf::Vector2f(0.0f, 0.0f));
}

Coin::~Coin()
{
}

bool Coin::update(sf::Time& frameTime)
{
	collider->update(item.getPosition());
	coinAnimation->play(frameTime);
	return false;
}