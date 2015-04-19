#include "Upgrade.h"


Upgrade::Upgrade()
{
	this->textureItem = AssetLibrary::instance()->textureMap;
	this->item.setTextureRect(sf::IntRect(256, 0, 288, 32));
}


Upgrade::Upgrade(TypeID typeID)
{
	this->idType = typeID;
	this->textureItem = AssetLibrary::instance()->textureMap;
	this->item.setTextureRect(sf::IntRect(160, 32, 192, 64));
}

Upgrade::~Upgrade()
{
}

bool Upgrade::update()
{
	itemCollider.update(item.getPosition());
	return false;
}

void Upgrade::setTypeID(TypeID typeID)
{
	this->idType = typeID;
}

void Upgrade::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(item);
}
