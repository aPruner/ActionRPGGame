#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "Tile.h"
#include "RoomConstants.h"

class TextureMap
{
private:
	// TextureMap Constants (not many so no need for constants object)
	const std::string c_spriteSheetListFilename = "sprites/dungeon_sprite_sheet_list.txt";
	const std::string c_spriteSheetFilename = "sprites/sprite_sheets/all_sprites.png";

	// TODO: Make a full weapon animation spritesheet using Pyxeledit (animate each weapon and then combine them)
	// For now, just animate the knife
	const std::string c_weaponAnimSpriteSheetFileName = "sprites/sprite_sheets/weapon_animations/knife_anim.png";
	const std::string c_weaponAnimSpriteSheetListFilename = "sprites/weapon_anim_list.txt";

	// Map of filenames to textures - for external single file textures
	std::map<std::string, sf::Texture> *m_textureMap;

	// Map of pre-defined texture names to vertex tuples (used for rooms) - for textures from original dungeon sprite sheet
	std::map<std::string, std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f>> *m_spriteSheetVecTupleTextureMap;

	// Map of pre-defined texture names to animation tuples (all sprite sheets)
	std::map<std::string, std::tuple<int, int, int, int, int>> *m_spriteSheetAnimTextureMap;

	// Map of pre-defined texture names to non animated tuples (don't have a number of frames)
	std::map<std::string, std::tuple<int, int, int, int>> * m_spriteSheetNonAnimTextureMap;

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

	// Get a texture from the SpriteSheet by name (non animated)
	sf::Texture& getTextureFromSpriteSheet(std::string const& textureName);

	// Get an animation vec tuple from a filename
	std::tuple<int, int, int, int, int>& getFilenameAnimVecTuple(std::string const& filename);

	// Fetch a vector tuple from m_spriteSheetTextureMap
	std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f>& getSpriteSheetVecTuple(std::string const& textureName);

	// Fetch a vector tuple with frames from m_spriteSheetAnimTextureMap
	std::tuple<int, int, int, int, int>& getSpriteSheetAnimVecTuple(std::string const& animName);

	sf::Texture& getSpriteSheet();
};