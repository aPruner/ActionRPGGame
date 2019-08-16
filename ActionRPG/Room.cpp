#include "Room.h"

Room::Room(TextureMap* textureMap)
{
	m_textureMap = textureMap;
	m_spriteSheet = m_textureMap->getTexture("sprites/sprite_sheets/all_sprites.png");
}

// Populate the VA
void Room::createRoom()
{
	int currentTile = 0;

	for (float i = 0.0f; i < c_maxRoomHeightTiles; i++)
	{
		for (float j = 0.0f; j < c_maxRoomWidthTiles; j++)
		{
			// Set the position of the current tile in the VA
			m_roomVA[currentTile].position = sf::Vector2f(j * c_tileSideLengthPixels, i * c_tileSideLengthPixels);
			m_roomVA[currentTile + 1].position = sf::Vector2f((j + 1) * c_tileSideLengthPixels, i * c_tileSideLengthPixels);
			m_roomVA[currentTile + 2].position = sf::Vector2f((j + 1) * c_tileSideLengthPixels, (i + 1) * c_tileSideLengthPixels);
			m_roomVA[currentTile + 3].position = sf::Vector2f(j * c_tileSideLengthPixels, (i + 1) * c_tileSideLengthPixels);

			// Now fill the VA texture coordinates (floor_1 for now)
			m_roomVA[currentTile].texCoords = sf::Vector2f(16, 64);
			m_roomVA[currentTile + 1].texCoords = sf::Vector2f(32, 64);
			m_roomVA[currentTile + 2].texCoords = sf::Vector2f(48, 80);
			m_roomVA[currentTile + 3].texCoords = sf::Vector2f(32, 80);

			currentTile += c_vertsInQuad;
		}
	}
}

sf::VertexArray *Room::getRoomVA()
{
	return &m_roomVA;
}

sf::Texture *Room::getSpriteSheet()
{
	return &m_spriteSheet;
}