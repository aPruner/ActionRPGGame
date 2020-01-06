#pragma once
#include <SFML/Graphics.hpp>
#include "RoomConstants.h"

class Tile
{
private:
	bool m_isSolid;
	sf::FloatRect m_bounds;

	int m_xPosition;
	int m_yPosition;

	// Type of tile, represented by a string
	std::string m_tileTextureName;

	// Texture Coords for this TileType
	sf::Vector2f m_tileTexCoords[RoomConstants::c_vertsInQuad];

	// Rectangle drawable for debugging
	sf::RectangleShape m_debugRect;
	bool m_drawDebugRect;

	// Set and color the debugging rect
	void initDebugRect();

public:
	Tile(std::string const& tileTextureName, bool isSolid, int xPosition, int yPosition);

	sf::FloatRect getBounds();

	// Debug helper methods
	bool getDebugStatus();
	sf::RectangleShape getDebugRectangleShape();
};