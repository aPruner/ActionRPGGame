#include "Room.h"

Room::Room(TextureMap* textureMap)
{
	m_floor_1Texture = textureMap->getSpriteSheetTextureFromTextureName("floor_1");
	m_tileTypeMap = new std::map<int, TileType>();
	
	// TODO: Figure out how the tileMap is going to work
	for (int i = 0; i < c_maxRoomHeightTiles; i++)
	{
		for (int j = 0; j < c_maxRoomWidthTiles; j++)
		{
			m_roomTileMap[i * c_maxRoomWidthTiles + j] = new Tile (FLOOR_1);
		}
	}
}

Room::~Room()
{
	delete m_tileTypeMap;
}

// Populate m_tileTypeMap
void Room::populateTileTypeMap()
{
	m_tileTypeMap->insert(std::pair<int, TileType>(25, FLOOR_1));
}

// Populate the VA
void Room::createRoom()
{
	// Configure the VA
	m_roomVA.setPrimitiveType(sf::PrimitiveType::Quads);
	m_roomVA.resize(c_roomVASize);

	int currentTile = 0;

	for (int i = 0; i < c_maxRoomHeightTiles; i++)
	{
		for (int j = 0; j < c_maxRoomWidthTiles; j++)
		{
			// Set the position of the current tile in the VA
			m_roomVA[currentTile].position = sf::Vector2f(
				(float) j * c_tileSideLengthPixels * c_roomScalingFactor,
				(float) i * c_tileSideLengthPixels * c_roomScalingFactor
			);
			m_roomVA[currentTile + 1].position = sf::Vector2f(
				(float)(j + 1) * c_tileSideLengthPixels * c_roomScalingFactor,
				(float) i * c_tileSideLengthPixels * c_roomScalingFactor
			);
			m_roomVA[currentTile + 2].position = sf::Vector2f(
				(float)(j + 1) * c_tileSideLengthPixels * c_roomScalingFactor,
				(float) (i + 1) * c_tileSideLengthPixels * c_roomScalingFactor
			);
			m_roomVA[currentTile + 3].position = sf::Vector2f(
				(float) j * c_tileSideLengthPixels * c_roomScalingFactor,
				(float) (i + 1) * c_tileSideLengthPixels * c_roomScalingFactor
			);

			// Now fill the VA texture coordinates (floor_1 for now)
			m_roomVA[currentTile].texCoords = sf::Vector2f(16, 64);
			m_roomVA[currentTile + 1].texCoords = sf::Vector2f(32, 64);
			m_roomVA[currentTile + 2].texCoords = sf::Vector2f(32, 80);
			m_roomVA[currentTile + 3].texCoords = sf::Vector2f(16, 80);

			currentTile += c_vertsInQuad;
		}
	}
}

sf::VertexArray& Room::getRoomVA()
{
	return m_roomVA;
}

sf::Texture *Room::getFloorTexture()
{
	return &m_floor_1Texture;
}