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
	sf::Texture* textureGround;
	std::vector<sf::Sprite> groundParts;
	//sf::Sprite groundPT;
	Collider* groundCollider;

private:
	void addGroundParts(int howMany);
};

