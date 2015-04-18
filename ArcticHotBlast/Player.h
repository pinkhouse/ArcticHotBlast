#pragma once

#include "SFML\Graphics.hpp"
#include "Animation.h"

class Player:
	public sf::Drawable
{
public:
	Player(sf::Vector2f position);
	~Player();

	bool update(sf::Time& frameTime, sf::Event &event);

private:
	sf::Time* frameTime;
#pragma region Animation
	Animation* walk;
	Animation* jump;
#pragma endregion
#pragma region Body parts
	sf::Texture textureBody;
	sf::Texture textureArm;
	sf::Sprite body;
	sf::Sprite arm;

	sf::Vector2f armLocation;
#pragma endregion
#pragma region Physics
	float gravity;
	bool isGrounded;
#pragma endregion
	
#pragma region Functions
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void checkInput(sf::Event& event);
#pragma endregion

};

