#pragma once
#include "SFML\Graphics.hpp"
#include <vector>
#include "Collider.h"
#include "CollidersDB.h"
class Platform
{
public:
	Platform();
	Platform(sf::Vector2f position, int size);
	~Platform();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	std::vector<sf::Sprite*> blocks;
	sf::Texture* textureMap;
	sf::Vector2f position;
	void generatePlatform(int size);
};

