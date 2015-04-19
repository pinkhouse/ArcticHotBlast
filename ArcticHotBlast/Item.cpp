#include "Item.h"
#include <iostream>

Item::Item()
{

}
Item::~Item()
{

}

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(item);
}