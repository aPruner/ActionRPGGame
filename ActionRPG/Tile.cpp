#include "Tile.h"

Tile::Tile(std::string const& tileTextureName, bool isSolid, int xPosition, int yPosition)
{
	m_tileTextureName = tileTextureName;
	m_isSolid = isSolid;
	m_xPosition = xPosition;
	m_yPosition = yPosition;
	m_bounds = sf::IntRect(
		xPosition * c_tileSideLengthPixels, yPosition * c_tileSideLengthPixels, c_tileSideLengthPixels, c_tileSideLengthPixels
	);
}

sf::IntRect Tile::getBounds()
{
	return m_bounds;
}