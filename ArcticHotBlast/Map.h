#pragma once
#include "SFML\Graphics.hpp"
#include <vector>
#include "Collider.h"
#include "CollidersDB.h"
#include "MapPartBuilder.h"
#pragma region map parts
#include "MapPart1.h"
#include "MapPart2.h"
#include "MapPart3.h"
#include "MapPart4.h"
#pragma endregion



class Map : public sf::Drawable
{
public:
	Map();
	~Map();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Texture* textureMap;
	std::vector<sf::Sprite> groundParts;
	Collider* groundCollider;
	void update();
private:
	void addGroundParts(int howMany);
	std::vector<Platform*> platforms;
	MapPartBuilder* mapPartBuilder;
	MapPart* mapPart;
};

