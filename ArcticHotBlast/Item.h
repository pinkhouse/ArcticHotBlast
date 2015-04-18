#pragma once
#include "SFML\Graphics.hpp"

class Item :
	public sf::Drawable
{
public:
	Item() =delete;
	virtual ~Item();

private:
	sf::RectangleShape name;
};

