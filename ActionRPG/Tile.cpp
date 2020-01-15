#include "Tile.h"

Tile::Tile(std::string const& tileTextureName, bool isSolid, int xPosition, int yPosition)
{
	m_tileTextureName = tileTextureName;
	m_isSolid = isSolid;
	m_xPosition = xPosition;
	m_yPosition = yPosition;
	m_bounds = sf::FloatRect(
		(float) (xPosition * RoomConstants::c_tileSideLengthPixels * RoomConstants::c_roomScalingFactor),
		(float) (yPosition * RoomConstants::c_tileSideLengthPixels * RoomConstants::c_roomScalingFactor),
		RoomConstants::c_tileSideLengthPixels * RoomConstants::c_roomScalingFactor,
		RoomConstants::c_tileSideLengthPixels * RoomConstants::c_roomScalingFactor
	);
	initDebugRect();
}

void Tile::initDebugRect()
{
	m_debugRect = sf::RectangleShape(sf::Vector2f(m_bounds.width, m_bounds.height));
	m_debugRect.setPosition(sf::Vector2f(
		(float)(m_xPosition * RoomConstants::c_tileSideLengthPixels * RoomConstants::c_roomScalingFactor),
		(float)(m_yPosition * RoomConstants::c_tileSideLengthPixels * RoomConstants::c_roomScalingFactor)
	));
	m_debugRect.setFillColor(sf::Color::Transparent);
	if (m_isSolid)
	{
		m_debugRect.setOutlineColor(sf::Color::Red);
	}
	else
	{
		m_debugRect.setOutlineColor(sf::Color::Blue);
	}
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