#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "Tile.h"

class TextureMap
{
private:
	const std::string c_tileListFilename = "sprites/tiles_list_v1.txt";
	const std::string c_spriteSheetFilename = "sprites/sprite_sheets/all_sprites.png";
	// TODO: Reduce duplicate code
	const static int c_vertsInQuad = 4;

	// Map of filenames to textures - for external single file texturese
	std::map<std::string, sf::Texture> *m_textureMap;

	// Map of pre-defined texture names to vertex tuples - for textures from sprite sheet
	std::map<std::string, std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f>> *m_spriteSheetTextureMap;

	std::map<std::string, std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f, int>> *m_spriteSheetAnimTextureMap;

	// Whole sprite sheet
	sf::Texture m_spriteSheet;

	// TODO: Load all textures from the sprite sheet into the above map
	// and create a separate data structure for indexing textures from the sprite sheet
	void loadTexturesFromTileList(std::string const& tileListFilename);
public:
	TextureMap();
	~TextureMap();
	
	// Fetch a texture from m_textureMap
	sf::Texture& getTextureFromFilename(std::string const& filename);

	// Fetch a vector tuple from m_spriteSheetTextureMap
	std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f>& getSpriteSheetVecTuple(std::string const& textureName);

	sf::Texture& getSpriteSheet();
};