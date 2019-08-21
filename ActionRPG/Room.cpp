#include "Room.h"

Room::Room(TextureMap* textureMap)
{
	m_textureMap = textureMap;
}

Room::~Room()
{
	for (int i = 0; i < c_maxRoomHeightTiles; i++)
	{
		for (int j = 0; j < c_maxRoomWidthTiles; j++)
		{
			delete m_roomTileMap[i * c_maxRoomWidthTiles + j];
		}
	}
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
				(float) (j * c_tileSideLengthPixels * c_roomScalingFactor),
				(float) (i * c_tileSideLengthPixels * c_roomScalingFactor)
			);
			m_roomVA[currentTile + 1].position = sf::Vector2f(
				(float) ((j + 1) * c_tileSideLengthPixels * c_roomScalingFactor),
				(float) (i * c_tileSideLengthPixels * c_roomScalingFactor)
			);
			m_roomVA[currentTile + 2].position = sf::Vector2f(
				(float) ((j + 1) * c_tileSideLengthPixels * c_roomScalingFactor),
				(float) ((i + 1) * c_tileSideLengthPixels * c_roomScalingFactor)
			);
			m_roomVA[currentTile + 3].position = sf::Vector2f(
				(float) (j * c_tileSideLengthPixels * c_roomScalingFactor),
				(float) ((i + 1) * c_tileSideLengthPixels * c_roomScalingFactor)
			);

			// Create a new tile in the tile map
			bool isSolid = false;
			if (i == 0 || i == c_maxRoomHeightTiles - 1 || j == 0 || j == c_maxRoomWidthTiles - 1)
			{
				isSolid = true;
			}
			Tile *tile = new Tile(c_floor1TextureName, isSolid, i, j);
			m_roomTileMap[i * c_maxRoomWidthTiles + j] = tile;

			// Now fill the VA texture coordinates
			std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f> vecTuple;
			vecTuple = m_textureMap->getSpriteSheetVecTuple(c_floor1TextureName);

			m_roomVA[currentTile].texCoords = sf::Vector2f(std::get<0>(vecTuple));
			m_roomVA[currentTile + 1].texCoords = sf::Vector2f(std::get<1>(vecTuple));
			m_roomVA[currentTile + 2].texCoords = sf::Vector2f(std::get<2>(vecTuple));
			m_roomVA[currentTile + 3].texCoords = sf::Vector2f(std::get<3>(vecTuple));

			currentTile += c_vertsInQuad;
		}
	}
}

sf::VertexArray& Room::getRoomVA()
{
	return m_roomVA;
}

Tile *Room::getTile(int x, int y)
{
	return m_roomTileMap[y * c_maxRoomWidthPixels + x];
}

Tile **Room::getRoomTileMap()
{
	return m_roomTileMap;
}

int Room::getMaxRoomWidthTiles()
{
	return c_maxRoomWidthTiles;
}

int Room::getMaxRoomHeightTiles()
{
	return c_maxRoomHeightTiles;
}