#pragma once
#include "SFML\Graphics.hpp"
class Collider :
	public sf::Drawable
{
public:
	Collider(sf::Vector2f size, sf::Vector2f position, sf::Vector2f origin = sf::Vector2f(-999.0f, -999.0f));
	Collider();
	~Collider();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(sf::Vector2f position);
	sf::FloatRect getBounds();
	bool isColliding;
	bool checkCollision(Collider& collider);
	void setCollidionStatus(bool isColliding);
	bool checkMouseOver();
	void setOrigin(sf::Vector2f origin);
	void setSize(sf::Vector2f size);
	sf::Vector2f getPosition();

private:
	sf::RectangleShape marker;
	bool _checkCollision(Collider& collider1, Collider& collider2);
};

