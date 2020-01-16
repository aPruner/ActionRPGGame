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

	// Read the first line to get the dimensions of the dungeon
	std::getline(dungeonFile, line);
	std::istringstream lineStream(line);
	std::vector<std::string> splitLine((std::istream_iterator<std::string>(lineStream)), std::istream_iterator<std::string>());
	int dungeonWidthTiles = std::stoi(splitLine.at(0));
	int dungeonHeightTiles = std::stoi(splitLine.at(1));
	

	while (std::getline(dungeonFile, line))
	{
		tilesLineVec.push_back(line);
	}

	Tile **dungeonRepresentation = new Tile *[dungeonWidthTiles * dungeonHeightTiles];

	for (int i = 0; i < dungeonHeightTiles; i++)
	{
		for (int j = 0; j < dungeonWidthTiles; j++)
		{
			std::string tileTextureName = RoomConstants::c_roomTxtCharMap.at(tilesLineVec.at(i)[j]);
			dungeonRepresentation[i * dungeonWidthTiles + j] = new Tile();
			// Create tile and insert in tile map
		}
	}
	
	Room *room = new Room(m_textureMap, dungeonWidthTiles, dungeonHeightTiles);
	



	// Step 1: Read chars into data structure (maybe vector of strings)
	// Step 2: Build new data structure with chars that can be used to index roomTxtCharMap (to get tile types)
	// Step 3: Loop through this new data structure and create logical tiles in a tile map with correct logic for each tile type
	// Step 4: Write logical data to the VAs and draw the logical tile map
	return room;
}