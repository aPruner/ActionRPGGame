#include "Room.h"

Room::Room(TextureMap* textureMap, RoomConstants* roomConstants, TileConstants* tileConstants, int widthTiles, int heightTiles, Tile *roomTileGrid[])
{
	m_textureMap = textureMap;
	m_roomConstants = roomConstants;
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

// TODO: draw the room as per the tileGrid, instead of hardcoded
// Populate the VertexArrays
void Room::initRoom()
{

	// Configure the VA
	m_roomVA.setPrimitiveType(sf::PrimitiveType::Quads);
	m_roomVA.resize(RoomConstants::c_roomVASize);

	// Configure wall layer VA
	m_roomWallLayerVA.setPrimitiveType(sf::PrimitiveType::Quads);
	m_roomWallLayerVA.resize(RoomConstants::c_roomVASize);

	int currentTile = 0;
	bool drawFloorTile = false;
	bool drawWallTile = false;

	for (int i = 0; i < RoomConstants::c_maxRoomHeightTiles; i++)
	{
		for (int j = 0; j < RoomConstants::c_maxRoomWidthTiles; j++)
		{
			int tileSideLengthPixels = RoomConstants::c_tileSideLengthPixels;
			int scalingFactor = RoomConstants::c_roomScalingFactor;
			// Set the position of the current tile in the VA
			m_roomVA[currentTile].position = sf::Vector2f(
				(float) (j * tileSideLengthPixels * scalingFactor),
				(float) (i * tileSideLengthPixels * scalingFactor)
			);
			m_roomVA[currentTile + 1].position = sf::Vector2f(
				(float) ((j + 1) * tileSideLengthPixels * scalingFactor),
				(float) (i * tileSideLengthPixels * scalingFactor)
			);
			m_roomVA[currentTile + 2].position = sf::Vector2f(
				(float) ((j + 1) * tileSideLengthPixels * scalingFactor),
				(float) ((i + 1) * tileSideLengthPixels * scalingFactor)
			);
			m_roomVA[currentTile + 3].position = sf::Vector2f(
				(float) (j * tileSideLengthPixels * scalingFactor),
				(float) ((i + 1) * tileSideLengthPixels * scalingFactor)
			);

			// Now fill the VA texture coordinates
			std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f> vecTuple;

			if (drawFloorTile) {
				vecTuple = m_textureMap->getSpriteSheetVecTuple(m_roomConstants->c_floor1TextureName);
				m_roomVA[currentTile].texCoords = std::get<0>(vecTuple);
				m_roomVA[currentTile + 1].texCoords = std::get<1>(vecTuple);
				m_roomVA[currentTile + 2].texCoords = std::get<2>(vecTuple);
				m_roomVA[currentTile + 3].texCoords = std::get<3>(vecTuple);
			}

			// When necessary, fill the wall layer VA
			if (drawWallTile)
			{
				// Set the position of the current tile in the WallLayerVA
				m_roomWallLayerVA[currentTile].position = sf::Vector2f(
					(float)(j * tileSideLengthPixels * scalingFactor),
					(float)(i * tileSideLengthPixels * scalingFactor)
				);
				m_roomWallLayerVA[currentTile + 1].position = sf::Vector2f(
					(float)((j + 1) * tileSideLengthPixels * scalingFactor),
					(float)(i * tileSideLengthPixels * scalingFactor)
				);
				m_roomWallLayerVA[currentTile + 2].position = sf::Vector2f(
					(float)((j + 1) * tileSideLengthPixels * scalingFactor),
					(float)((i + 1) * tileSideLengthPixels * scalingFactor)
				);
				m_roomWallLayerVA[currentTile + 3].position = sf::Vector2f(
					(float)(j * tileSideLengthPixels * scalingFactor),
					(float)((i + 1) * tileSideLengthPixels * scalingFactor)
				);
				vecTuple = m_textureMap->getSpriteSheetVecTuple(m_roomConstants->c_floor1TextureName);
				m_roomWallLayerVA[currentTile].texCoords = std::get<0>(vecTuple);
				m_roomWallLayerVA[currentTile + 1].texCoords = std::get<1>(vecTuple);
				m_roomWallLayerVA[currentTile + 2].texCoords = std::get<2>(vecTuple);
				m_roomWallLayerVA[currentTile + 3].texCoords = std::get<3>(vecTuple);
			}

			currentTile += RoomConstants::c_vertsInQuad;
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