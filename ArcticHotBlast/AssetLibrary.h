#pragma once
#include "SFML\Graphics.hpp"
class AssetLibrary
{
public:
	static AssetLibrary* instance();
	void initialize();
	~AssetLibrary();

	static sf::RenderWindow* mainWindow;
	static sf::View* mainCamera;

	static sf::Texture* textureBodyPlayer;
	static sf::Texture* textureWeapon;
	static sf::Texture* textureMap;
	static sf::Texture* texturePinguin;
	static sf::Texture* textureSnowman;

	void loadTextures();
protected:
	AssetLibrary();
private:
	static AssetLibrary* _instance;
};

