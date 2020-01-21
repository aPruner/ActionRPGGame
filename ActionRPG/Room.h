#pragma once
#include <SFML/Graphics.hpp>
#include "TextureMap.h"
#include "RoomConstants.h"

// TODO: Decide if Room class will be needed, or if it will just be Dungeon instead
// Based on this decision, rename Room class to Dungeon or create a new Dungeon class
class Room
{
private:
	// TileConstants instance - for now, used to fetch wall top mid texture name
	TileConstants *m_tileConstants;

	// Width and Height of the room in tiles
	int m_widthTiles;
	int m_heightTiles;

	// Tile Grid (logically represents the room)
	Tile **m_roomTileGrid;

	// Instance of the textureMap
	TextureMap *m_textureMap;

	// VertexArray representing the roomTileMap (this is drawn)
	sf::VertexArray m_roomVA;

	// VertexArray for walls that are drawn ontop (and around) the tiles
	sf::VertexArray m_roomWallLayerVA;

public:
	Room(TextureMap *textureMap, TileConstants* tileConstants, int roomWidthTiles, int roomHeightTiles, Tile *roomTileGrid[]);
	~Room();

	// Write to the VA to create the room (so it can be drawn)
	void initRoom();

	// Getters and Setters
	// Getters

	// Getter for the room (under layer)
	sf::VertexArray& getRoomVA();

	// Getter for the wall layer VA
	sf::VertexArray& getRoomWallLayerVA();

	// Get a tile from the tile map at logical position x, y
	Tile *getTile(int x, int y);

	// Get the tilemap
	Tile **getRoomTileGrid();

	int getMaxRoomWidthTiles();
	int getMaxRoomHeightTiles();
};