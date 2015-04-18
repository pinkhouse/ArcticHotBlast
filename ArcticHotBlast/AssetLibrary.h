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

	static sf::Texture* textureBody;
	static sf::Texture* textureWeapon;
	static sf::Texture* textureMap;

	void loadTextures();
protected:
	AssetLibrary();
private:
	static AssetLibrary* _instance;
};

