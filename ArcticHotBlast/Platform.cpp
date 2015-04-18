#include "Platform.h"
#include "AssetLibrary.h"

Platform::Platform(sf::Vector2f position, int size)
{
	this->textureMap = AssetLibrary::instance()->textureMap;
	this->position = position;
	this->generatePlatform(size);
}

Platform::Platform()
{
}

Platform::~Platform()
{
}

void Platform::generatePlatform(int size)
{
	for (int i = 0; i < size; i++)
	{
		sf::Sprite* block = new sf::Sprite();
		block->setTexture(*textureMap);
		if (i == 0)
		{
			block->setTextureRect(sf::IntRect(0, 32, 32, 32));
		}
		else
		{
			if (i == size - 1)
			{
				block->setTextureRect(sf::IntRect(64, 32, 32, 32));
			}
			else
			{
				block->setTextureRect(sf::IntRect(32, 32, 32, 32));
			}
		}
		block->setPosition(sf::Vector2f(position.x + 32 * i, position.y));
		blocks.push_back(block);
	}
	Collider* collider = new Collider(sf::Vector2f(size * 32.0f, 32.0f), position, sf::Vector2f(0.0f, 0.0f));
	CollidersDB::instance()->platforms->push_back(collider);
}

void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (sf::Sprite* block : blocks)
	{
		target.draw(*block);
	}
}