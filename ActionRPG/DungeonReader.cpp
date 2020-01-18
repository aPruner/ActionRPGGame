#include "DungeonReader.h"

DungeonReader::DungeonReader(TextureMap *textureMap)
{
	m_textureMap = textureMap;
}

DungeonReader::~DungeonReader()
{

}

// TODO: Decide how rooms/dungeons will work, for now, dungeon reader will only read in a room
// but later on the .txt file could represent a whole dungeon (multiple rooms with corridors connecting them)
// if I want to design it that way - maybe my decision on procedural generation will influence this?
Room *DungeonReader::readDungeon(std::string const& dungeonFilename)
{
	// initialize static RoomConstants and TileConstants maps
	m_roomConstants = new RoomConstants();
	m_tileConstants = new TileConstants();

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

	Tile **tileGrid = new Tile *[dungeonWidthTiles * dungeonHeightTiles];

	for (int i = 0; i < dungeonHeightTiles; i++)
	{
		for (int j = 0; j < dungeonWidthTiles; j++)
		{
			// Get the necessary data to create this tile
			char tileIndex = tilesLineVec.at(i)[j];
			TileProperties tileProperties = m_tileConstants->c_tilePropertiesMap.at(tileIndex);

			// Create tile and insert in the tile grid
			tileGrid[i * dungeonWidthTiles + j] = new Tile(&tileProperties, j, i);
		}
	}
	
	return new Room(m_textureMap, m_roomConstants, m_tileConstants, dungeonWidthTiles, dungeonHeightTiles, tileGrid);
}