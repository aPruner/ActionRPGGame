#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class TextureMap
{
private:
	const std::string c_tileListFilename = "sprites/tiles_list_v1.txt";

	// Map of filenames to textures - for external single file textures
	std::map<std::string, sf::Texture> *m_textureMap;

	// Map of textureNames to textureCoordinates (tuple of 4 Vector2f) - for sprite sheet textures
	std::map<std::string, std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f>> *m_textureCoordsMap;

	// TODO: Load all textures from the sprite sheet into the above map
	// and create a separate data structure for indexing textures from the sprite sheet
	void loadTexturesFromTileList(std::string const& tileListFilename);
public:
	TextureMap();
	~TextureMap();
	
	// Fetch a texture from the map
	sf::Texture& getTextureFromFilename(std::string const& textureName);
};