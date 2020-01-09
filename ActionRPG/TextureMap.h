#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "Tile.h"
#include "RoomConstants.h"
#include "TextureMapConstants.h"

class TextureMap
{
private:
	// TextureMapConstants object
	TextureMapConstants *m_textureMapConstants;

	// Map of filenames to spritesheets - need this since we are dealing with more than one spritesheet now
	std::map<std::string, sf::Texture> *m_spriteSheetMap;

	// Map of filenames to textures - for external single file textures
	std::map<std::string, sf::Texture> *m_textureMap;

	// Map of pre-defined texture names to vertex tuples (used for rooms) - for textures from original dungeon sprite sheet
	std::map<std::string, std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f>> *m_spriteSheetVecTupleTextureMap;

	// Map of pre-defined texture names to animation tuples (all sprite sheets)
	std::map<std::string, std::tuple<int, int, int, int, int>> *m_spriteSheetAnimTextureMap;

	// Map of pre-defined texture names to non animated tuples (don't have a number of frames)
	std::map<std::string, std::tuple<int, int, int, int>> * m_spriteSheetNonAnimTextureMap;

	// Original dungeon sprite sheet, from which the room is drawn
	sf::Texture m_roomSpriteSheet;

	// TODO: Load all textures from the sprite sheet into the above map
	// and create a separate data structure for indexing textures from the sprite sheet

	// This function reads a tile list and inserts into the above maps the relevant texture coordinates for each texture name in the list
	void loadTexturesFromTileList(std::string const& tileListFilename);

	// Read a SpriteSheet into the sprite sheet map
	void addSpriteSheet(std::string const& spriteSheetFilename);

public:
	TextureMap();
	~TextureMap();
	
	// Fetch a texture from m_textureMap
	sf::Texture& getTextureFromFilename(std::string const& filename);

	// Get an animation vec tuple from a filename
	std::tuple<int, int, int, int, int>& getFilenameAnimVecTuple(std::string const& filename);

	// Fetch a vector tuple from m_spriteSheetTextureMap
	std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f>& getSpriteSheetVecTuple(std::string const& textureName);

	// Fetch a vector tuple with frames from m_spriteSheetAnimTextureMap
	std::tuple<int, int, int, int, int>& getSpriteSheetAnimVecTuple(std::string const& animName);

	// Get a sprite sheet from the sprite sheet map by filename
	sf::Texture& getSpriteSheetFromFilename(std::string const& spriteSheetFilename);

	// Getters and Setters
	// Getters
	TextureMapConstants *getTextureMapConstants();
	sf::Texture& getRoomSpriteSheet();
};