#pragma once
#include <SFML/Graphics.hpp>
#include "TextureMap.h"

class Room
{
private:
	// Room constants
	const static int c_maxRoomWidthPixels = 256;
	const static int c_maxRoomHeightPixels = 256;
	// Tiles are 16x16 in the sprite sheet
	// TODO: Scale these up a bit
	const static int c_tileSideLengthPixels = 16;
	const static int c_maxRoomWidthTiles = c_maxRoomWidthPixels / c_tileSideLengthPixels;
	const static int c_maxRoomHeightTiles = c_maxRoomHeightPixels / c_tileSideLengthPixels;
	const static int c_vertsInQuad = 4;
	const static size_t c_roomVASize = c_maxRoomWidthPixels * c_maxRoomHeightTiles * c_vertsInQuad;

	const std::string c_spriteSheetFilename = "sprites/sprite_sheets/all_sprites.png";

	// VertexArray representing the room
	sf::VertexArray m_roomVA;

	// Instance of the textureMap
	TextureMap *m_textureMap;

	// Sprite sheet for all of the game sprites/textures
	sf::Texture m_spriteSheet;

public:
	Room(TextureMap *textureMap);

	// Write to the VA to create the room (so it can be drawn)
	void createRoom();

	// Getter for the VA, which will need to be drawn by the Engine
	sf::VertexArray& getRoomVA();

	sf::Texture *getSpriteSheet();
};