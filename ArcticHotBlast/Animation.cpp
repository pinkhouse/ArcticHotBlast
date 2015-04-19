#include "Animation.h"
#include <iostream>

Animation::Animation(sf::Sprite& sprite, int numberOfFrames, float fps,
	sf::Vector2i animationSheetStart, sf::Vector2i spriteSize) : sprite(sprite)
{
	this->numberOfFrames = numberOfFrames;
	this->fps = fps;
	this->animationSheetStart = animationSheetStart;
	this->spriteSize = spriteSize;
	this->rect = sf::IntRect(animationSheetStart.x, animationSheetStart.y, spriteSize.x, spriteSize.y);
	this->animationFrameTime = sf::seconds(1.0 / this->fps);
	this->currentFrame = 0;
}

Animation::Animation() : sprite(sf::Sprite())
{}


Animation::~Animation()
{
}

void Animation::play(sf::Time frameTime)
{
	elapsedTime += frameTime;
	if (elapsedTime.asSeconds() >= animationFrameTime.asSeconds())
	{ 
		if (currentFrame < numberOfFrames - 1)
		{
			currentFrame += 1;
		}
		else
		{
			currentFrame = 0;
		}
		elapsedTime = sf::seconds(0.0f);
		this->sprite.setTextureRect(sf::IntRect((animationSheetStart.x + spriteSize.x * currentFrame), animationSheetStart.y,
			spriteSize.x, spriteSize.y));
	}
}

void Animation::playB(sf::Time frameTime)
{
	elapsedTime += frameTime;
	if (elapsedTime.asSeconds() >= animationFrameTime.asSeconds())
	{
		if (currentFrame > 0)
		{
			currentFrame -= 1;
		}
		else
		{
			currentFrame = numberOfFrames - 1;
		}
		elapsedTime = sf::seconds(0.0f);
		this->sprite.setTextureRect(sf::IntRect((animationSheetStart.x + spriteSize.x * currentFrame), animationSheetStart.y,
			spriteSize.x, spriteSize.y));
	}
}

void Animation::changeFps(float fps)
{
	this->fps = fps;
	this->animationFrameTime = sf::seconds(1.0 / this->fps);
}

int Animation::getCurrentFrame()
{
	return currentFrame;
}