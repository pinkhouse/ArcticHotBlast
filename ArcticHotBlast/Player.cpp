#include "Player.h"
#include "CollidersDB.h"
#include <iostream>
#include "AssetLibrary.h"

Player::Player(sf::Vector2f position)
{
	textureBody = AssetLibrary::instance()->textureBody;
	body.setTexture(*textureBody);
	this->body.setOrigin(body.getLocalBounds().width/2, body.getLocalBounds().height);

	this->body.setPosition(position);
	this->weapon.setPosition(position);
	this->gravity = 980.0f;
	this->walkSpeed = 250.0f;
	this->currentSpeed = 0.0f;
	this->isGrounded = false;
	this->touchingBorder = false;
	this->fallingSpeed = 0.0f;;
	this->collider = new Collider(sf::Vector2f(56.0f, 128.0), this->body.getPosition(), sf::Vector2f(28.0f,128));
	CollidersDB::instance()->player = collider;
}

Player::~Player()
{

}

bool Player::update(sf::Time& frameTime, sf::Event &event)
{
	this->frameTime = &frameTime;
	this->checkInput(event);
	potentialEnergy();
	if (collider->checkCollision(*CollidersDB::instance()->ground))
	{
		isGrounded = true;
		body.setPosition(body.getPosition().x, CollidersDB::instance()->ground->getBounds().top-1);
	}
	if (!isGrounded)
	{
		this->body.move(0, fallingSpeed * frameTime.asSeconds());
	}

	if (currentSpeed != 0.0f)
	{
		if (!touchingBorder)
		{
			this->body.move(currentSpeed * frameTime.asSeconds(), 0);
		}
		else
		{
			if (currentSpeed > 0.0f)
			{
				this->body.move(currentSpeed * frameTime.asSeconds(), 0);
				touchingBorder = false;
			}
			else
			{
				currentSpeed = 0.0f;
			}
		}
		if (collider->checkCollision(*CollidersDB::instance()->leftBorder))
		{
			touchingBorder = true;
			body.setPosition(CollidersDB::instance()->leftBorder->getBounds().left +
				CollidersDB::instance()->leftBorder->getBounds().width + collider->getBounds().width/2, body.getPosition().y);
		}
	}
	weapon.update(body.getPosition(), event);
	collider->update(body.getPosition());
	checkPlatformsCollision();
	if (isGrounded)
	{
		fallingSpeed = 0.0f;
	}
	return false;
}


void Player::checkInput(sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isGrounded)
	{
		fallingSpeed = -650;
		isGrounded = false;
		standingOn = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//shoot
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			currentSpeed = 0;
		}
		else
		{
			if (currentSpeed > -walkSpeed)
			{
				currentSpeed -= 3 * walkSpeed * this->frameTime->asSeconds();
			}
			else
			{
				if (currentSpeed < -walkSpeed)
				{
					currentSpeed = -walkSpeed;
				}
			}
		}
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			currentSpeed = 0;
		}
		else
		{
			if (currentSpeed < walkSpeed)
			{
				currentSpeed += 3 * walkSpeed *this->frameTime->asSeconds();
			}
			else
			{
				if (currentSpeed > walkSpeed)
				{
					currentSpeed = walkSpeed;
				}
			}
		}
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (currentSpeed > 0)
		{
			currentSpeed -= 4 * walkSpeed*this->frameTime->asSeconds();
			if (currentSpeed < 0)
			{
				currentSpeed = 0;
			}
		}
		else
		{
			if (currentSpeed < 0)
			{
				currentSpeed += 4 * walkSpeed*this->frameTime->asSeconds();
			}
			if (currentSpeed > 0)
			{
				currentSpeed = 0;
			}
		}
	}
}
void Player::potentialEnergy()
{
	if (!isGrounded)
	{
		this->fallingSpeed += this->gravity * frameTime->asSeconds();
	}
}
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body);
	target.draw(weapon);
}

void Player::checkPlatformsCollision()
{
	if (standingOn != 0)
	{
		if (!collider->checkCollision(*standingOn))
		{
			this->isGrounded = false;
			standingOn = 0;
		}
	}
	else
	{
		if (platformsToCheck.size() > 0)
		{
			for (Collider* platform : platformsToCheck)
			{
				if (collider->checkCollision(*platform))
				{
					body.setPosition(sf::Vector2f(body.getPosition().x, platform->getBounds().top));
					this->isGrounded = true;
					standingOn = platform;
				}
			}
		}
		platformsToCheck.clear();
		for (Collider* platform : *CollidersDB::instance()->platforms)
		{
			if (collider->getBounds().top + collider->getBounds().height <= platform->getBounds().top)
			{
				platformsToCheck.push_back(platform);
			}
		}
	}
}