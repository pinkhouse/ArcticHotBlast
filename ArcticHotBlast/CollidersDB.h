#pragma once
#include "Collider.h"
#include "SFML\Graphics.hpp"
#include "Item.h"

class CollidersDB
{
public:
	static CollidersDB* instance();
	static Collider* player;
	static Collider* ground;
	static Collider* leftBorder;
	static std::vector<Collider*>* obstacles;
	static std::vector<Collider*>* items;
	static std::vector<Collider*>* platforms;
	static std::vector<Collider*>* buttons;
	static int collidersID;
	static int ID;
	void draw(sf::RenderWindow& window);
	void clearDb();
protected:
	CollidersDB();
private:
	static CollidersDB* _instance;
};

