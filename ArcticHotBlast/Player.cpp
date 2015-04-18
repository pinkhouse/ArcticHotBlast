#include "Player.h"
#include "CollidersDB.h"
#include <iostream>
#include "AssetLibrary.h"

Player::Player(sf::Vector2f position)
{
	textureBody = AssetLibrary::instance()->textureBody;
	textureArm = AssetLibrary::instance()->textureArm;
	body.setTexture(*textureBody);
	arm.setTexture(*textureArm);
	this->body.setOrigin(body.getLocalBounds().width/2, body.getLocalBounds().height);
	this->arm.setOrigin(5, arm.getLocalBounds().height / 2);
	this->body.setPosition(position);
	this->arm.setPosition(position.x,position.y+75);
	this->armLocation = sf::Vector2f(body.getPosition().x - arm.getPosition().x, body.getPosition().y - arm.getPosition().y);
	this->armRotation = 0;

	this->gravity = 980.0f;
	this->walkSpeed = 250.0f;
	this->currentSpeed = 0.0f;
	this->armRotated = false;
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
	collider->update(body.getPosition());
	this->arm.setPosition(body.getPosition().x + armLocation.x, body.getPosition().y + armLocation.y);
	this->arm.setRotation(static_cast<float>(armRotation));
	return false;
}


void Player::checkInput(sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isGrounded)
	{
		fallingSpeed = -600;
		isGrounded = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//shoot
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
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
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up && !armRotated)
	{
		armRotated = true;
		if (armRotation > -215)
		armRotation -= 45;
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
	{
		armRotated = false;
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down && !armRotated)
	{
		armRotated = true;
		if (armRotation < 45)
		armRotation += 45;
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down)
	{
		armRotated = false;
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
	target.draw(arm);
}

