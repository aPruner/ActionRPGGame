#include "Room.h"

Room::Room(TextureMap* textureMap)
{
	m_textureMap = textureMap;
}

Room::~Room()
{
	for (int i = 0; i < RoomConstants::c_maxRoomHeightTiles; i++)
	{
		for (int j = 0; j < RoomConstants::c_maxRoomWidthTiles; j++)
		{
			delete m_roomTileMap[i * RoomConstants::c_maxRoomWidthTiles + j];
		}
	}
}

// Populate the VA
void Room::createRoom()
{

	// Configure the VA
	m_roomVA.setPrimitiveType(sf::PrimitiveType::Quads);
	m_roomVA.resize(RoomConstants::c_roomVASize);

	// Configure wall layer VA
	m_roomWallLayerVA.setPrimitiveType(sf::PrimitiveType::Quads);
	m_roomWallLayerVA.resize(RoomConstants::c_roomVASize);

	int currentTile = 0;

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

			// TODO: Implement system where text files (containing rows of chars representing tiles) are read in and converted into rooms
			// Create a new tile in the tile map
			bool isSolid = false;
			std::string tileTextureName;
			if (i == 0 && j == 0) // top left corner case
			{
				isSolid = true;
				tileTextureName = "wall_side_top_left";
			}
			else if (i == 0 && j == RoomConstants::c_maxRoomWidthTiles - 1) // top right corner case
			{
				isSolid = true;
				tileTextureName = "wall_side_top_right";
			}
			else if (i == RoomConstants::c_maxRoomHeightTiles - 1 && j == 0) // bottom left corner case
			{
				isSolid = true;
				tileTextureName = "wall_side_front_left";
			}
			else if (i == RoomConstants::c_maxRoomHeightTiles - 1 && j == RoomConstants::c_maxRoomWidthTiles - 1) // bottom right corner case
			{
				isSolid = true;
				tileTextureName = "wall_side_front_right";
			}
			else if (i == 1 && j == 0) // under top left corner case
			{
				isSolid = true;
				tileTextureName = "wall_side_mid_left";
			}
			else if (i == 1 && j == RoomConstants::c_maxRoomWidthTiles - 1) // Under top right corner case
			{
				isSolid = true;
				tileTextureName = "wall_side_mid_right";
			}
			else if (i == RoomConstants::c_maxRoomHeightTiles - 2 && j == 0)
			{
				isSolid = true;
				tileTextureName = "wall_side_mid_left";
			}
			else if (i == RoomConstants::c_maxRoomHeightTiles - 2 && j == RoomConstants::c_maxRoomWidthTiles - 1)
			{
				isSolid = true;
				tileTextureName = "wall_side_mid_right";
			}
			else if (i == 1) // top wall case
			{
				isSolid = true;
				tileTextureName = "wall_mid";
			}
			else if (i == RoomConstants::c_maxRoomHeightTiles - 2) // bottom wall top part case
			{
				isSolid = true;
				tileTextureName = "wall_top_mid";
			}
			else if (i == 0) // top wall top part case
			{
				isSolid = true;
				tileTextureName = "wall_top_mid";

			}
			else if (j == 0) // left wall case
			{
				isSolid = true;
				tileTextureName = "wall_side_mid_left";
			}
			else if (i == RoomConstants::c_maxRoomHeightTiles - 1) // bottom wall case
			{
				isSolid = true;
				tileTextureName = "wall_mid";
			}
			else if (j == RoomConstants::c_maxRoomWidthTiles - 1) // right wall case
			{
				isSolid = true;
				tileTextureName = "wall_side_mid_right";
			}

			Tile *tile = new Tile(c_floor1TextureName, isSolid, i, j);
			m_roomTileMap[i * RoomConstants::c_maxRoomWidthTiles + j] = tile;

			// Now fill the VA texture coordinates
			std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f> vecTuple;
			vecTuple = m_textureMap->getSpriteSheetVecTuple(c_floor1TextureName);

			if (!isSolid) {
				m_roomVA[currentTile].texCoords = std::get<0>(vecTuple);
				m_roomVA[currentTile + 1].texCoords = std::get<1>(vecTuple);
				m_roomVA[currentTile + 2].texCoords = std::get<2>(vecTuple);
				m_roomVA[currentTile + 3].texCoords = std::get<3>(vecTuple);
			}

			// When necessary, fill the wall layer VA
			if (isSolid)
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
				vecTuple = m_textureMap->getSpriteSheetVecTuple(tileTextureName);
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
	return m_roomTileMap[y * RoomConstants::c_maxRoomWidthPixels + x];
}

Tile **Room::getRoomTileMap()
{
	return m_roomTileMap;
}

int Room::getMaxRoomWidthTiles()
{
	return RoomConstants::c_maxRoomWidthTiles;
}

int Room::getMaxRoomHeightTiles()
{
	return RoomConstants::c_maxRoomHeightTiles;
}