#include "AssetLibrary.h"
#include <iostream>

AssetLibrary* AssetLibrary::_instance = 0;
sf::View* AssetLibrary::mainCamera = 0;
sf::RenderWindow* AssetLibrary::mainWindow = 0;
sf::Texture* AssetLibrary::textureMap = 0;
sf::Texture* AssetLibrary::texturePlayer = 0;

AssetLibrary::AssetLibrary()
{
}


AssetLibrary::~AssetLibrary()
{
}

AssetLibrary* AssetLibrary::instance()
{
	if (_instance = 0)
	{
		_instance = new AssetLibrary();
	}
	return _instance;
}

void AssetLibrary::loadTextures()
{
	if (this->texturePlayer->loadFromFile("data/img/player/body.png"))
	{
		std::cout << "PLAYER BODY TEXTURE LOADED\n";
	}
	if (this->textureMap->loadFromFile("data/img/map.png"))
	{
		std::cout << "MAP TEXTURE LOADED\n";
	}
}

void AssetLibrary::initialize()
{
	this->texturePlayer = new sf::Texture();
	this->textureMap = new sf::Texture();
	this->loadTextures();
}