#include "TileConstants.h"

// TODO: Be aware of wall top part edge case, it may (seemingly) need to be solid if it is part of a top (back) wall,
// but it shouldn't be solid as part of a bottom (front) wall

TileProperties::TileProperties(bool isSolid, bool isAnimated, std::string const& tileTextureName)
{
	m_isSolid = isSolid;
	m_isAnimated = isAnimated;
	m_tileTextureName = tileTextureName;
}

TileProperties::~TileProperties()
{
}

bool TileProperties::getIsSolid()
{
	return m_isSolid;
}

bool TileProperties::getIsAnimated()
{
	return m_isAnimated;
}

std::string TileProperties::getTileTextureName()
{
	return m_tileTextureName;
}