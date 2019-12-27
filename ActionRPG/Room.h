#pragma once
#include <SFML/Graphics.hpp>
#include "TextureMap.h"
#include "RoomConstants.h"

class Room
{
private:
	// Room constants are all static values, so no need for constants object

	// TODO: Map TileType enum to tileType strings
	const std::string c_floor1TextureName = "floor_1";

	// Tile map (logically represents the room)
	Tile *m_roomTileMap[RoomConstants::c_roomTileMapSize];

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