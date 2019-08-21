#include "Tile.h"

Tile::Tile(std::string const& tileTextureName, bool isSolid, int xPosition, int yPosition)
{
	m_tileTextureName = tileTextureName;
	m_isSolid = isSolid;
	m_xPosition = xPosition;
	m_yPosition = yPosition;
	m_bounds = sf::FloatRect(
		(float) (xPosition * c_tileSideLengthPixels * c_roomScalingFactor),
		(float) (yPosition * c_tileSideLengthPixels * c_roomScalingFactor),
		c_tileSideLengthPixels * c_roomScalingFactor,
		c_tileSideLengthPixels * c_roomScalingFactor
	);
	initDebugRect();
}

void Tile::initDebugRect()
{
	m_debugRect = sf::RectangleShape(sf::Vector2f(m_bounds.width, m_bounds.height));
	m_debugRect.setPosition(sf::Vector2f(
		(float)(m_xPosition * c_tileSideLengthPixels * c_roomScalingFactor),
		(float)(m_yPosition * c_tileSideLengthPixels * c_roomScalingFactor)
	));
	m_debugRect.setFillColor(sf::Color::Transparent);
	m_debugRect.setOutlineColor(sf::Color::Blue);
	m_debugRect.setOutlineThickness((float)1);
	m_drawDebugRect = true;
}

sf::FloatRect Tile::getBounds()
{
	return m_bounds;
}

sf::RectangleShape Tile::getDebugRectangleShape()
{
	return m_debugRect;
}

bool Tile::getDebugStatus()
{
	return m_drawDebugRect;
}