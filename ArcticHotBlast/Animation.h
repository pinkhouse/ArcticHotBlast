#include "SFML\Graphics.hpp"
#pragma once
class Animation
{
public:
	Animation(sf::Sprite& sprite, int numberOfFrames, float fps = 7.0,
		sf::Vector2i animationSheetStart = sf::Vector2i(0, 0), sf::Vector2i spriteSize = sf::Vector2i(128, 96));
	Animation();
	virtual ~Animation();
	void play(sf::Time frameTime);
	void playB(sf::Time frameTime);
	void changeFps(float fps);
	int getCurrentFrame();
	float fps;
private:
	sf::Time animationFrameTime;
	sf::Time elapsedTime;
	sf::Sprite& sprite;
	sf::IntRect rect;
	int numberOfFrames;
	sf::Vector2i spriteSize;
	sf::Vector2i animationSheetStart;
	int currentFrame;
};

