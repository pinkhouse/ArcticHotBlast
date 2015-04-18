#pragma once
#include "SFML\Graphics.hpp"
#include <vector>
class Platform
{
public:
	Platform();
	~Platform();
private:
	std::vector<sf::Sprite*>* blocks;
	sf::Texture textureMap;
};

