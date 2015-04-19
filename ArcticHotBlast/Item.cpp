#include "Item.h"
#include <iostream>
#include "CollidersDB.h"

Item::Item()
{

}
Item::~Item()
{
	CollidersDB::instance()->items->erase(std::remove(CollidersDB::instance()->items->begin(), CollidersDB::instance()->items->end(),
		collider), CollidersDB::instance()->items->end());
}

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(item);
}