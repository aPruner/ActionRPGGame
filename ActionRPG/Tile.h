#pragma once
#include <SFML/Graphics.hpp>
#include "RoomConstants.h"
#include "TileConstants.h"

class Tile
{
private:
	bool m_isSolid;
	bool m_isAnimated;
	bool m_isTopWallDrawn;
	sf::FloatRect m_boundingBox;

	// Flag for if the tile is colliding with a GameObject
	bool m_isCollidingWithGameObject;

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
	Tile(TileProperties *tileProperties, int xPosition, int yPosition);

	// Getters and Setters
	// Getters
	sf::FloatRect getBoundingBox();
	std::string const& getTextureName();
	bool getIsTopWallDrawn();
	TileProperties *getTileProperties();
	bool getIsCollidingWithGameObject();

	// Debug helper getters
	bool getDebugStatus();
	sf::RectangleShape getDebugRect();

	// Setters

	// TODO: Maybe consolidate these two setters into one setTileProperties setter?
	void setIsSolid(bool isSolid);
	void setIsAnimated(bool isAnimated);

	void setIsCollidingWithGameObject(bool isCollidingWithGameObject);
};