#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class TextureMap
{
private:
	// Map of filenames to textures
	std::map<std::string, sf::Texture> *m_textureMap;

	// TODO: Load all textures from the sprite sheet into the above map
	// and create a separate data structure for indexing textures from the sprite sheet
public:
	TextureMap();
	~TextureMap();
	
	// Fetch a texture from the map
	sf::Texture& getTexture(std::string const& filename);
};