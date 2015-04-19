#include "Upgrade.h"
#include "CollidersDB.h"

Upgrade::Upgrade()
{
	initialize();
	this->idType = TypeID::Battery;
}


Upgrade::Upgrade(TypeID typeID, sf::Vector2f position)
{
	initialize();
	this->idType = typeID;
	item.setPosition(position);
	CollidersDB::instance()->items->push_back(collider);
	collider->update(item.getPosition());
}

void Upgrade::initialize()
{
	this->textureItem = AssetLibrary::instance()->textureMap;
	this->item.setTexture(*textureItem);
	this->item.setTextureRect(sf::IntRect(256, 0, 32, 32));
	this->collider = new Collider(sf::Vector2f(32.0f, 32.0f), item.getPosition(), sf::Vector2f(0.0f, 0.0f));
	taken = false;
	ID = CollidersDB::instance()->ID;
	CollidersDB::instance()->ID++;
}

Upgrade::~Upgrade()
{
}

bool Upgrade::update(sf::Time& frameTime)
{
	return taken;
}

void Upgrade::setTypeID(TypeID typeID)
{
	this->idType = typeID;
}
