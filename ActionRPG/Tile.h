#pragma once
#include <SFML/Graphics.hpp>

class Tile
{
private:
	// TODO: See if I can reduce duplicate code, as this constant is already defined in Room.h
	const static int c_vertsInQuad = 4;
	const static int c_tileSideLengthPixels = 16;

	bool m_isSolid;
	sf::IntRect m_bounds;

	int m_xPosition;
	int m_yPosition;

	// Type of tile, represented by a string
	std::string m_tileTextureName;

	// Texture Coords for this TileType
	sf::Vector2f m_tileTexCoords[c_vertsInQuad];

public:
	Tile(std::string const& tileTextureName, bool isSolid, int xPosition, int yPosition);

	sf::IntRect getBounds();
};