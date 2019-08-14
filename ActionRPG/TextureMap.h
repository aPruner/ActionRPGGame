#pragma once
#include <map>
#include <SFML/Graphics.hpp>

class TextureMap
{
private:
	// Map of filenames to textures
	std::map<std::string, sf::Texture> *textureMap;

	// The TextureMap class is a singleton
	static TextureMap *instance;
	static void addTexture(std::string const& filename);
public:
	TextureMap();
	
	// Fetch a texture from the map
	static sf::Texture& getTexture(std::string const& filename);
};