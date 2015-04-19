#include "Pinguin.h"

Pinguin::Pinguin()
{
	this->gravity = 980.0f;
	this->walkSpeed = 250.0f;
	this->currentSpeed = 0.0f;
	this->isGrounded = false;
	this->fallingSpeed = 0.0f;;
	this->texturePinguin = AssetLibrary::instance()->texturePinguin;
	this->pinguin.setTexture(*texturePinguin);
	this->pinguin.setTextureRect(sf::IntRect(0, 0, 64, 96));
	pinguin.setOrigin(32, 96);
}

Pinguin::Pinguin(sf::Vector2f position)
{
	standingOn = 0;
	this->gravity = 980.0f;
	this->walkSpeed = 250.0f;
	this->currentSpeed = 0.0f;
	this->isGrounded = false;
	this->fallingSpeed = 0.0f;;

	this->texturePinguin = AssetLibrary::instance()->texturePinguin;
	this->pinguin.setTexture(*texturePinguin);
	this->pinguin.setTextureRect(sf::IntRect(0, 0, 64, 96));
	pinguin.setOrigin(32, 96);
	pinguin.setPosition(position);

	this->enemyCollider = new Collider(sf::Vector2f(64, 92), pinguin.getPosition(), sf::Vector2f(32, 96));
	enemyID = 0;
	isAlive = true;
}


Pinguin::~Pinguin()
{
}

bool Pinguin::update(sf::Time& frameTime)
{

	potentialEnergy(frameTime);
	
	if (enemyCollider->checkCollision(*CollidersDB::instance()->ground))
	{
		this->isGrounded = true;
		pinguin.setPosition(pinguin.getPosition().x, CollidersDB::instance()->ground->getBounds().top - 1);
	}
	enemyCollider->update(pinguin.getPosition());
	checkPlatformsCollision();
	if (this->isGrounded)
	{
		fallingSpeed = 0.0f;
	}
	return false;
}
void Pinguin::potentialEnergy(sf::Time& frameTime)
{
	if (!isGrounded)
	{
		this->fallingSpeed += this->gravity * frameTime.asSeconds();
		pinguin.move(0, fallingSpeed * frameTime.asSeconds());
	}
}
void Pinguin::attack()
{

}

void Pinguin::move()
{

}



void Pinguin::checkPlatformsCollision()
{
	if (standingOn != 0)
	{
		if (enemyCollider->checkCollision(*standingOn))
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
				if (enemyCollider->checkCollision(*platform))
				{
					pinguin.setPosition(sf::Vector2f(pinguin.getPosition().x, platform->getBounds().top-1));
					this->isGrounded = true;
					standingOn = platform;
				}
			}
		}
		platformsToCheck.clear();
		for (Collider* platform : *CollidersDB::instance()->platforms)
		{
			if (enemyCollider->getBounds().top + enemyCollider->getBounds().height <= platform->getBounds().top)
			{
				platformsToCheck.push_back(platform);
			}
		}
	}
}

void Pinguin::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(pinguin);
}