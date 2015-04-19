#include "Player.h"
#include "CollidersDB.h"
#include <iostream>
#include "AssetLibrary.h"

Player::Player(sf::Vector2f position)
{
	textureBody = AssetLibrary::instance()->textureBodyPlayer;
	body.setTexture(*textureBody);
	body.setTextureRect(sf::IntRect(0, 0, 96, 128));
	this->body.setOrigin(body.getLocalBounds().width/2, body.getLocalBounds().height);

	this->body.setPosition(position);
	updateHookPoint();
	this->weapon = Weapon(armHookPoint);
	this->gravity = 980.0f;
	this->walkSpeed = 250.0f;
	this->currentSpeed = 0.0f;
	this->isGrounded = false;
	this->touchingBorder = false;
	this->fallingSpeed = 0.0f;;
	this->collider = new Collider(sf::Vector2f(56.0f, 116.0f), this->body.getPosition(), sf::Vector2f(28.0f,116));
	CollidersDB::instance()->player = collider;
	facingRight = true;
	this->walkRight = new Animation(body, 3, 12.0f, sf::Vector2i(0, 0), sf::Vector2i(96, 128));
	this->walkLeft = new Animation(body, 3, 12.0f, sf::Vector2i(0, 128), sf::Vector2i(96, 128));
	this->stayRight = new Animation(body, 2, 4.0f, sf::Vector2i(0, 256), sf::Vector2i(96, 128));
	this->stayLeft = new Animation(body, 2, 4.0f, sf::Vector2i(192, 256), sf::Vector2i(96, 128));

	this->airRight = new Animation(body, 1, 0, sf::Vector2i(96, 384), sf::Vector2i(96, 128));
	this->airLeft = new Animation(body, 1, 0, sf::Vector2i(96, 512), sf::Vector2i(96, 128));

	this->jumpLeft = new Animation(body, 1, 0, sf::Vector2i(0, 512), sf::Vector2i(96, 128));
	this->jumpRight = new Animation(body, 1, 0, sf::Vector2i(0, 384), sf::Vector2i(96, 128));
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
		body.setPosition(body.getPosition().x, CollidersDB::instance()->ground->getBounds().top - 1);
	}
	if (!isGrounded)
	{
		this->body.move(0, fallingSpeed * frameTime.asSeconds());
	}


	if (fallingSpeed >= 0)
	{
		if (currentSpeed != 0.0f)
		{
			if (currentSpeed > 0.0)
			{
				if (facingRight)
				{
					walkRight->play(frameTime);
				}
				else
				{
					walkLeft->playB(frameTime);
				}
			}
			else
			{
				if (!facingRight)
				{
					walkLeft->play(frameTime);
				}
				else
				{
					walkRight->playB(frameTime);
				}
			}
		}
	}
	else
	{
		if (fallingSpeed > -575 && fallingSpeed < -500)
		{
			if (!facingRight)
			{
				jumpLeft->play(frameTime);
			}
			else
			{
				jumpRight->playB(frameTime);
			}
		}
		else
		{
			if (!facingRight)
			{
				airLeft->play(frameTime);
			}
			else
			{
				airRight->playB(frameTime);
			}
		}
	}
	if (currentSpeed == 0 && fallingSpeed == 0)
	{
		if (facingRight)
		{
			stayRight->play(frameTime);
		}
		else
		{
			stayLeft->play(frameTime);
		}
	}

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
			CollidersDB::instance()->leftBorder->getBounds().width + collider->getBounds().width / 2, body.getPosition().y);
	}


	updateHookPoint();
	this->facingRight = weapon.update(armHookPoint, event);
	collider->update(body.getPosition());
	checkPlatformsCollision();
	if (isGrounded)
	{
		fallingSpeed = 0.0f;
	}
	return false;
}

void Player::updateHookPoint()
{
	armHookPoint = sf::Vector2f(body.getPosition().x - 8.0f, body.getPosition().y - 70.0f);
}


void Player::checkInput(sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isGrounded)
	{
		fallingSpeed = -575;
		isGrounded = false;
		standingOn = 0;
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
	if (facingRight)
	{
		target.draw(body);
		target.draw(weapon);
	}
	else
	{
		target.draw(weapon);
		target.draw(body);
	}
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