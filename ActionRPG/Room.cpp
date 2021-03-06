#include "Room.h"

Room::Room(TextureMap* textureMap, TileConstants* tileConstants, int widthTiles, int heightTiles, Tile *roomTileGrid[])
{
	m_textureMap = textureMap;
	m_tileConstants = tileConstants;
	m_roomTileGrid = roomTileGrid;

	m_widthTiles = widthTiles;
	m_heightTiles = heightTiles;
}

Room::~Room()
{
	for (int i = 0; i < RoomConstants::c_maxRoomHeightTiles; i++)
	{
		for (int j = 0; j < RoomConstants::c_maxRoomWidthTiles; j++)
		{
			delete m_roomTileGrid[i * RoomConstants::c_maxRoomWidthTiles + j];
		}
	}
	delete[] &m_roomTileGrid;
}

// Populate the VertexArrays
void Room::initRoom()
{

	// Configure the VA
	m_roomVA.setPrimitiveType(sf::PrimitiveType::Quads);
	m_roomVA.resize(RoomConstants::c_roomVASize);

	// Configure wall layer VA - only for drawing any walls that are on top of floor tiles
	m_roomWallLayerVA.setPrimitiveType(sf::PrimitiveType::Quads);
	m_roomWallLayerVA.resize(RoomConstants::c_roomVASize);

	int currentTileIndex = 0;
	bool drawFloorTile = false;
	bool drawWallTile = false;

	for (int i = 0; i < m_heightTiles; i++)
	{
		for (int j = 0; j < m_widthTiles; j++)
		{
			int tileSideLengthPixels = RoomConstants::c_tileSideLengthPixels;
			int scalingFactor = RoomConstants::c_roomScalingFactor;

			Tile* currentTile = m_roomTileGrid[i * m_widthTiles + j];

			// Set the position of the current tile in the VA
			m_roomVA[currentTileIndex].position = sf::Vector2f(
				(float) (j * tileSideLengthPixels * scalingFactor),
				(float) (i * tileSideLengthPixels * scalingFactor)
			);
			m_roomVA[currentTileIndex + 1].position = sf::Vector2f(
				(float) ((j + 1) * tileSideLengthPixels * scalingFactor),
				(float) (i * tileSideLengthPixels * scalingFactor)
			);
			m_roomVA[currentTileIndex + 2].position = sf::Vector2f(
				(float) ((j + 1) * tileSideLengthPixels * scalingFactor),
				(float) ((i + 1) * tileSideLengthPixels * scalingFactor)
			);
			m_roomVA[currentTileIndex + 3].position = sf::Vector2f(
				(float) (j * tileSideLengthPixels * scalingFactor),
				(float) ((i + 1) * tileSideLengthPixels * scalingFactor)
			);

			// Now fill the VA texture coordinates
			std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f> vecTuple;
			vecTuple = m_textureMap->getSpriteSheetVecTuple(currentTile->getTextureName());
			m_roomVA[currentTileIndex].texCoords = std::get<0>(vecTuple);
			m_roomVA[currentTileIndex + 1].texCoords = std::get<1>(vecTuple);
			m_roomVA[currentTileIndex + 2].texCoords = std::get<2>(vecTuple);
			m_roomVA[currentTileIndex + 3].texCoords = std::get<3>(vecTuple);

			// If necessary, draw the wall top mid overtop of the current floor tile
			if (currentTile->getIsTopWallDrawn())
			{
				// Set the position of the current tile in the wallLayerVA
				m_roomWallLayerVA[currentTileIndex].position = sf::Vector2f(
					(float)(j * tileSideLengthPixels * scalingFactor),
					(float)(i * tileSideLengthPixels * scalingFactor)
				);
				m_roomWallLayerVA[currentTileIndex + 1].position = sf::Vector2f(
					(float)((j + 1) * tileSideLengthPixels * scalingFactor),
					(float)(i * tileSideLengthPixels * scalingFactor)
				);
				m_roomWallLayerVA[currentTileIndex + 2].position = sf::Vector2f(
					(float)((j + 1) * tileSideLengthPixels * scalingFactor),
					(float)((i + 1) * tileSideLengthPixels * scalingFactor)
				);
				m_roomWallLayerVA[currentTileIndex + 3].position = sf::Vector2f(
					(float)(j * tileSideLengthPixels * scalingFactor),
					(float)((i + 1) * tileSideLengthPixels * scalingFactor)
				);

				// Get the vecTuple for the wall top mid texture
				vecTuple = m_textureMap->getSpriteSheetVecTuple(m_tileConstants->c_wallTopMidTextureName);

				// Write the wall top mid over this floor tile
				m_roomWallLayerVA[currentTileIndex].texCoords = std::get<0>(vecTuple);
				m_roomWallLayerVA[currentTileIndex + 1].texCoords = std::get<1>(vecTuple);
				m_roomWallLayerVA[currentTileIndex + 2].texCoords = std::get<2>(vecTuple);
				m_roomWallLayerVA[currentTileIndex + 3].texCoords = std::get<3>(vecTuple);
			}

			currentTileIndex += RoomConstants::c_vertsInQuad;
		}
	}
}

sf::VertexArray& Room::getRoomVA()
{
	return m_roomVA;
}

sf::VertexArray& Room::getRoomWallLayerVA()
{
	return m_roomWallLayerVA;
}

Tile *Room::getTile(int x, int y)
{
	return m_roomTileGrid[y * RoomConstants::c_maxRoomWidthPixels + x];
}

Tile **Room::getRoomTileGrid()
{
	return m_roomTileGrid;
}

int Room::getMaxRoomWidthTiles()
{
	return RoomConstants::c_maxRoomWidthTiles;
}

int Room::getMaxRoomHeightTiles()
{
	return RoomConstants::c_maxRoomHeightTiles;
}