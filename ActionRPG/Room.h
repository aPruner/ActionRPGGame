#pragma once
#include <SFML/Graphics.hpp>
#include "TextureMap.h"

class Room
{
private:
	// Room constants
	const static int c_maxRoomWidthPixels = 256;
	const static int c_maxRoomHeightPixels = 256;
	const static int c_tileSideLengthPixels = 16;
	const static int c_maxRoomWidthTiles = c_maxRoomWidthPixels / c_tileSideLengthPixels;
	const static int c_maxRoomHeightTiles = c_maxRoomHeightPixels / c_tileSideLengthPixels;
	const static int c_vertsInQuad = 4;
	const static int c_roomScalingFactor = 2;
	const static int c_roomTileMapSize = c_maxRoomWidthTiles * c_maxRoomHeightTiles;
	const static size_t c_roomVASize = c_roomTileMapSize * c_vertsInQuad;

	// TODO: Map TileType enum to tileType strings
	const std::string c_floor1TextureName = "floor_1";

	// Tile map (logically represents the room)
	Tile *m_roomTileMap[c_roomTileMapSize];

	// Instance of the textureMap
	TextureMap *m_textureMap;

	// VertexArray representing the roomTileMap (this is drawn)
	sf::VertexArray m_roomVA;

	// TODO: Add a data structure that represents a room read in from a file

public:
	Room(TextureMap *textureMap);
	~Room();

	// Write to the VA to create the room (so it can be drawn)
	void createRoom();

	// Getter for the VA, which will need to be drawn by the Engine
	sf::VertexArray& getRoomVA();

	// Get a tile from the tile map at logical position x, y
	Tile *getTile(int x, int y);

	// Get the tilemap
	Tile **getRoomTileMap();

	int getMaxRoomWidthTiles();
	int getMaxRoomHeightTiles();
};