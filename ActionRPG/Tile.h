#pragma once
#include <SFML/Graphics.hpp>
#include "RoomConstants.h"
#include "TileConstants.h"

class Tile
{
private:
	bool m_isSolid;
	bool m_isAnimated;
	sf::FloatRect m_bounds;

	int m_xPosition;
	int m_yPosition;

	// Properties object for tiles of this type
	TileProperties *m_tileProperties;

	// Type of tile, represented by a string
	std::string m_textureName;

	// Rectangle drawable for debugging
	sf::RectangleShape m_debugRect;
	bool m_drawDebugRect;

	// Set and color the debugging rect
	void initDebugRect();

public:
	Tile(std::string const& tileTextureName, TileProperties *tileProperties, int xPosition, int yPosition);

	// Getters and Setters
	// Getters
	sf::FloatRect getBounds();
	std::string const& getTextureName();
	TileProperties *getTileProperties();

	// Debug helper getters
	bool getDebugStatus();
	sf::RectangleShape getDebugRectangleShape();

	// Setters
	void setIsSolid(bool isSolid);
	void setIsAnimated(bool isAnimated);
};