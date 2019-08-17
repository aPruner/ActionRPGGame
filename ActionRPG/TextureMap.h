#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class TextureMap
{
private:
	const std::string c_tileListFilename = "sprites/tiles_list_v1.txt";
	const std::string c_spriteSheetFilename = "sprites/sprite_sheets/all_sprites.png";

	// Map of filenames to textures - for external single file textures
	std::map<std::string, sf::Texture> *m_textureMap;

	// Map of pre-defined texture names to textures - for textures from sprite sheet
	std::map<std::string, sf::Texture> *m_spriteSheetTextureMap;

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

	// Fetch a texture from m_spriteSheetTextureMap
	sf::Texture& getSpriteSheetTextureFromTextureName(std::string const& textureName);
};