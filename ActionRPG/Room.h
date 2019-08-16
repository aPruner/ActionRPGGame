#pragma once
#include <SFML/Graphics.hpp>

class Room
{
private:
	// Room constants
	const static int c_maxRoomWidth = 256;
	const static int c_maxRoomHeight = 256;

	// VertexArray representing the room
	sf::VertexArray m_room;
public:
	Room();
};