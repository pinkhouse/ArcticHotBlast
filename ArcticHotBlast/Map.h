#pragma once
#include "SFML\Graphics.hpp"
#include <vector>
#include "Collider.h"
#include "CollidersDB.h"
class Map : public sf::Drawable
{
public:
	Map();
	~Map();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Texture* textureMap;
	std::vector<sf::Sprite> groundParts;
	Collider* groundCollider;

private:
	void addGroundParts(int howMany);
};

