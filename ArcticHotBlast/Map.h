#pragma once
#include "SFML\Graphics.hpp"
#include <deque>
#include "Collider.h"
#include "CollidersDB.h"
#include "MapPartBuilder.h"
#include "MapPart1.h"

class Map : public sf::Drawable
{
public:
	Map();
	~Map();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Texture* textureMap;
	std::deque<sf::Sprite> groundParts;
	Collider* groundCollider;
	void update();
	
private:
	void addGroundParts(int howMany);
	std::vector<MapPart*> mapParts;
	void addMapPart(MapPartBuilder* mapPartBuilder, float startingPoint);
	void clearOffScreen();
	void scrollGround();
	void generateMap(int numberOfParts);
};

