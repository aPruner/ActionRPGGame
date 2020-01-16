#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Room.h"
#include "TextureMap.h"

class DungeonReader {
private:
	// Instance of the TextureMap
	TextureMap *m_textureMap;
	
	// Instance of RoomConstants
	RoomConstants *m_roomConstants;

	// Instance of TileConstants
	TileConstants *m_tileConstants;

public:
	DungeonReader(TextureMap *textureMap);
	~DungeonReader();

	Room *readDungeon(std::string const& dungeonFilename);
};