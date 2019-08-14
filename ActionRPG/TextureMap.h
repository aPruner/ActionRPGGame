#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class TextureMap
{
private:
	// Map of filenames to textures
	std::map<std::string, sf::Texture> textures;

	// The TextureMap class is a singleton
	static TextureMap *instance;
public:
	TextureMap();
	
	// Fetch a texture from the map
	static sf::Texture& getTexture(std::string const& filename);
};