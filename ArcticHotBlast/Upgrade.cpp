#include "Upgrade.h"


Upgrade::Upgrade()
{
	initialize();
}


Upgrade::Upgrade(TypeID typeID, sf::Vector2f position)
{
	this->idType = typeID;
	item.setPosition(position);
	initialize();
}

void Upgrade::initialize()
{
	this->textureItem = AssetLibrary::instance()->textureMap;
	this->item.setTexture(*textureItem);
	this->item.setTextureRect(sf::IntRect(256, 0, 32, 32));
}

Upgrade::~Upgrade()
{
}

bool Upgrade::update(sf::Time& frameTime)
{
	collider->update(item.getPosition());
	return false;
}

void Upgrade::setTypeID(TypeID typeID)
{
	this->idType = typeID;
}
