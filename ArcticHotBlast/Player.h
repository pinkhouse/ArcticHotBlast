#pragma once

#include "SFML\Graphics.hpp"
#include "Animation.h"
#include "Collider.h"
#include "Weapon.h"
#include "Map.h"

class Player:
	public sf::Drawable
{
public:
	Player(sf::Vector2f position);
	~Player();

	bool update(sf::Time& frameTime, sf::Event &event, Map& map);

private:
	sf::Time* frameTime;
	Collider* collider;
	int score;

#pragma region Animation
	Animation* walkRight;
	Animation* walkLeft;
	Animation* stayRight;
	Animation* stayLeft;
	Animation* jumpRight;
	Animation* jumpLeft;
	Animation* airRight;
	Animation* airLeft;
#pragma endregion

	sf::Texture* textureBody;
	sf::Sprite body;
	Weapon weapon;
	sf::Vector2f armHookPoint;
	bool facingRight;

#pragma region Physics
	bool touchingBorder;
	bool isGrounded;
	bool standingOnGround;
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
	void checkGroundCollision();
	void checkBorderCollision();
	void checkItemsCollisions(Map& map);
	void move(sf::Time& frameTime);
	void updateHookPoint();
	void animate(sf::Time& frameTime);
#pragma endregion

};

