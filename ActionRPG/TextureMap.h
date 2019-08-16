#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class TextureMap
{
private:
	// Map of filenames to textures
	std::map<std::string, sf::Texture> *m_textureMap;
public:
	TextureMap();
	~TextureMap();
	
	// Fetch a texture from the map
	sf::Texture& getTexture(std::string const& filename);
};