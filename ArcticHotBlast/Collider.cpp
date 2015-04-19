#include "Collider.h"
#include <iostream>
#include "CollidersDB.h"

Collider::Collider(sf::Vector2f size, sf::Vector2f position, sf::Vector2f origin)
{
	this->setSize(size);
	if (origin == sf::Vector2f(-999.0f, -999.0f))
	{
		this->marker.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
	}
	else
	{
		this->setOrigin(origin);
	}
	this->marker.setPosition(position);
	this->marker.setOutlineColor(sf::Color::Green);
	this->marker.setFillColor(sf::Color::Transparent);
	this->marker.setOutlineThickness(1.0f);
	this->isColliding = false;
}

Collider::Collider()
{
}


Collider::~Collider()
{
}

void Collider::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(marker);
}

void Collider::update(sf::Vector2f position)
{
	this->marker.setPosition(position);
}

sf::FloatRect Collider::getBounds()
{
	return this->marker.getGlobalBounds();
}

void Collider::setSize(sf::Vector2f size)
{
	this->marker.setSize(size);
}

void Collider::setOrigin(sf::Vector2f origin)
{
	this->marker.setOrigin(origin);
}

bool Collider::checkCollision(Collider& collider)
{
	if (_checkCollision(collider, *this) || _checkCollision(*this, collider))
	{
		collider.setCollidionStatus(true);
		return true;
	}
	else
	{
		collider.setCollidionStatus(false);
		return false;
	}
	
}

bool Collider::_checkCollision(Collider& collider1, Collider& collider2)
{
	Collider* colliders[] = { &collider1, &collider2 };
	if (colliders[0]->getBounds().left < colliders[1]->getBounds().left + colliders[1]->getBounds().width &&
		colliders[0]->getBounds().left + colliders[0]->getBounds().width > colliders[1]->getBounds().left &&
		colliders[0]->getBounds().top < colliders[1]->getBounds().top + colliders[1]->getBounds().height &&
		colliders[0]->getBounds().height + colliders[0]->getBounds().top > colliders[1]->getBounds().top)
	{
		this->isColliding = true;
		return true;
	}
	else
	{
		this->isColliding = false;
		return false;
	}
}

void Collider::setCollidionStatus(bool isColliding)
{
	if (isColliding)
	{
		this->marker.setOutlineColor(sf::Color::Red);
	}
	else
	{
		this->marker.setOutlineColor(sf::Color::Green);
	}
}

sf::Vector2f Collider::getPosition()
{
	return this->marker.getPosition();
}

sf::Vector2f Collider::getCenter()
{
	return sf::Vector2f(this->getBounds().left + this->getBounds().width / 2, this->getBounds().top + this->getBounds().height / 2);
}