#pragma once
#include "Room.h"
#include "TextureMap.h"

class DungeonReader {
private:
	TextureMap *m_textureMap;
public:
	DungeonReader(TextureMap *textureMap);
	~DungeonReader();

	Room *readDungeon(std::string const& dungeonFilename);
};