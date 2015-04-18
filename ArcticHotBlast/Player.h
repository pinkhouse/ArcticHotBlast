#pragma once

#include "SFML\Graphics.hpp"
#include "Animation.h"
#include "Collider.h"
#include "Weapon.h"

class Player:
	public sf::Drawable
{
public:
	Player(sf::Vector2f position);
	~Player();

	bool update(sf::Time& frameTime, sf::Event &event);

private:
	sf::Time* frameTime;
	Collider* collider;

#pragma region Animation
	Animation* walk;
	Animation* jump;
#pragma endregion

	sf::Texture* textureBody;
	sf::Sprite body;
	Weapon weapon;

#pragma region Physics
	bool touchingBorder;
	bool isGrounded;
	float fallingSpeed;
	float gravity;
	float walkSpeed;
	float currentSpeed;
	std::vector<Collider*>platformsToCheck;
	Collider* standingOn = 0;
#pragma endregion
	
#pragma region Functions
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void checkInput(sf::Event& event);
	void potentialEnergy();
	void checkPlatformsCollision();
#pragma endregion

};

