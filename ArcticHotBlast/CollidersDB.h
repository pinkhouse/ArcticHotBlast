#pragma once
#include "Collider.h"
#include "SFML\Graphics.hpp"
class CollidersDB
{
public:
	static CollidersDB* instance();
	static Collider* player;
	static Collider* ground;
	static std::vector<Collider*>* obstacles;
	static std::vector<Collider*>* items;
	static std::vector<Collider*>* platforms;
	static std::vector<Collider*>* enemies;
	static std::vector<Collider*>* buttons;
	void draw(sf::RenderWindow& window);
	static sf::RenderWindow* gWindow;
	void clearDb();
protected:
	CollidersDB();
private:
	static CollidersDB* _instance;
};

