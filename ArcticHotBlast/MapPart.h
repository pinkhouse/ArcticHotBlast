#pragma once
#include "SFML\Graphics.hpp"
#include <vector>

class MapPart
{
public:
	MapPart();
	~MapPart();
	void addPlatform(sf::Sprite* platform);
	void addEnemySpawnSpot(sf::Vector2f* enemySpawnSpot);
	void addItemSpawnSpot(sf::Vector2f* itemSpawnSpot);
private:
	std::vector<sf::Sprite*>* platforms;
	std::vector<sf::Vector2f*>* enemySpawnSpots;
	std::vector<sf::Vector2f*>* itemSpawnSpots;
};

