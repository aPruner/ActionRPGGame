#include "Tile.h"

Tile::Tile(TileProperties *tileProperties, int xPosition, int yPosition)
{
	m_tileProperties = tileProperties;
	m_isSolid = tileProperties->getIsSolid();
	m_isAnimated = tileProperties->getIsAnimated();
	m_textureName = tileProperties->getTileTextureName();
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

// Getters and Setters
// Getters
sf::FloatRect Tile::getBounds()
{
	return m_bounds;
}

std::string const& Tile::getTextureName()
{
	return m_textureName;
}

TileProperties* Tile::getTileProperties()
{
	return m_tileProperties;
}

sf::RectangleShape Tile::getDebugRectangleShape()
{
	return m_debugRect;
}

bool Tile::getDebugStatus()
{
	return m_drawDebugRect;
}

// Setters
void Tile::setIsSolid(bool isSolid)
{
	m_isSolid = isSolid;
}


void Tile::setIsAnimated(bool isAnimated)
{
	m_isAnimated = isAnimated;
}