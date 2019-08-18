#pragma once
#include <SFML/Graphics.hpp>
#include "TextureMap.h"
#include "Tile.h"

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
	const static int c_roomScalingFactor = 2;
	const static int c_roomTileMapSize = c_maxRoomWidthTiles * c_maxRoomHeightTiles;
	const static size_t c_roomVASize = c_roomTileMapSize * c_vertsInQuad;

	// Tile map (logically represents the room)
	Tile *m_roomTileMap[c_roomTileMapSize];

	// VertexArray representing the roomTileMap (this is drawn)
	sf::VertexArray m_roomVA;

	// Floor texture
	sf::Texture m_floor_1Texture;

	// Map of ints to tileTypes to easily represent the room with an int array
	std::map<int, TileType> *m_tileTypeMap;

	// Populate m_tileTypeMap
	void populateTileTypeMap();

public:

	Room(TextureMap *textureMap);
	~Room();

	// Write to the VA to create the room (so it can be drawn)
	void createRoom();

	// Getter for the VA, which will need to be drawn by the Engine
	sf::VertexArray& getRoomVA();

	sf::Texture *getFloorTexture();
};