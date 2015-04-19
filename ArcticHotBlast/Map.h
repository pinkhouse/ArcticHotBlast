#pragma once
#include "SFML\Graphics.hpp"
#include <deque>
#include "Collider.h"
#include "CollidersDB.h"
#include "MapPartBuilder.h"

#pragma region map parts
#include "MapPart1.h"
#include "MapPart2.h"
#include "MapPart3.h"
#include "MapPart4.h"
#pragma endregion

#include "Pinguin.h"
class Map : public sf::Drawable
{
public:
	Map();
	~Map();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Texture* textureMap;
	std::deque<sf::Sprite> groundParts;
	Collider* groundCollider;
	void update(sf::Time& frameTime);
	std::vector<MapPart*> mapParts;
	
private:
	void addGroundParts(int howMany);
	void addMapPart(MapPartBuilder* mapPartBuilder, float startingPoint);
	void clearOffScreen();
	bool offScreenCleared[2];
	void scrollGround();
	void generateMap(int numberOfParts);

	Pinguin* pinguin;
};

