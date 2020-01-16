#include "DungeonReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

DungeonReader::DungeonReader(TextureMap *textureMap)
{
	m_textureMap = textureMap;
}

DungeonReader::~DungeonReader()
{

}

// TODO: Decide how rooms/dungeons will work, for now, dungeon reader will only read in a room
// but technically, the txt file could represent a whole dungeon (multiple rooms with corridors connecting them)
Room *DungeonReader::readDungeon(std::string const& dungeonFilename)
{
	std::ifstream dungeonFile;
	dungeonFile.open(dungeonFilename);

	std::string line;
	std::vector<std::string> tilesLineVec = std::vector<std::string>();

	int maxLineLength = 0;

	while (std::getline(dungeonFile, line))
	{
		tilesLineVec.push_back(line);
		if (line.length() > maxLineLength)
		{
			maxLineLength = line.length();
		}
	}

	// The width of the dungeon will be the length of the longest line in the file
	int dungeonWidthTiles = maxLineLength;
	// The height of the dungeon will be the length of the lines vector
	int dungeonHeightTiles = tilesLineVec.size();
	Room* room = new Room(m_textureMap, dungeonWidthTiles, dungeonHeightTiles);
	// TODO: finish this method



	// Step 1: Read chars into data structure (maybe vector of strings)
	// Step 2: Build new data structure with chars that can be used to index roomTxtCharMap (to get tile types)
	// Step 3: Loop through this new data structure and create logical tiles in a tile map with correct logic for each tile type
	// Step 4: Write logical data to the VAs and draw the logical tile map
}