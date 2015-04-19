#pragma once
#include "SFML\Graphics.hpp"
class Cursor : public sf::Drawable
{
public:
	Cursor();
	~Cursor();
	void update(sf::RenderWindow& window);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Texture textureCursor;
	sf::Sprite cursor;
};

