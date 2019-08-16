#pragma once
#include <SFML/Graphics.hpp>
#include "TextureMap.h"

class Room
{
private:
	// Room constants
	const static int c_maxRoomWidth = 256;
	const static int c_maxRoomHeight = 256;

	// VertexArray representing the room
	sf::VertexArray m_roomVA;

	// Instance of the textureMap
	TextureMap *m_textureMap;

	// Sprite sheet for all of the game sprites/textures
	sf::Texture m_spriteSheet;

public:
	Room(TextureMap *textureMap);

	// Write to the VA to create the room (so it can be drawn)
	void createRoom();

	// Getter for the VA, which will need to be drawn by the Engine
	sf::VertexArray *getRoomVA();
};