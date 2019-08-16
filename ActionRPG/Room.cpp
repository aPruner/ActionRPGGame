#include "Room.h"

Room::Room(TextureMap* textureMap)
{
	m_textureMap = textureMap;
	m_spriteSheet = m_textureMap->getTexture("sprites/sprite_sheets/all_sprites.png");
}

// Populate the VA
void Room::createRoom()
{

}

sf::VertexArray *Room::getRoomVA()
{
	return &m_roomVA;
}