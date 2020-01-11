#include "GameObject.h"

sf::Sprite GameObject::getSprite()
{
	return m_sprite;
}

sf::FloatRect GameObject::getBoundingBox()
{
	return m_sprite.getGlobalBounds();
}

sf::Vector2f GameObject::getOrigin()
{
	return m_origin;
}

// Returns -1 if outside
int GameObject::getXPositionInTileMap()
{
	int xPositionInTileMap = (int) m_origin.x / RoomConstants::c_roomScalingFactor / RoomConstants::c_tileSideLengthPixels;
	if (m_origin.x < 0)
	{
		return -1;
	}
	return xPositionInTileMap;
}

// Returns -1 if outside
int GameObject::getYPositionInTileMap()
{
	int yPositionInTileMap = (int) m_origin.y / RoomConstants::c_roomScalingFactor / RoomConstants::c_tileSideLengthPixels;
	if (m_origin.y < 0)
	{
		return -1;
	}
	return yPositionInTileMap;
}

void GameObject::initDebugRect()
{
	// Init outline rect
	m_debugRectOutline = sf::RectangleShape(sf::Vector2f(getBoundingBox().width, getBoundingBox().height));
	m_debugRectOutline.setOrigin(getOrigin());
	m_debugRectOutline.setFillColor(sf::Color::Transparent);
	m_debugRectOutline.setOutlineColor(sf::Color::Red);
	m_debugRectOutline.setOutlineThickness((float)1);

	// Init Origin rect
	m_debugRectOrigin = sf::RectangleShape(sf::Vector2f((float)4, (float)4));
	m_debugRectOrigin.setOrigin(getOrigin());
	m_debugRectOrigin.setFillColor(sf::Color::Green);
	m_debugRectOrigin.setOutlineColor(sf::Color::Green);
	m_debugRectOrigin.setOutlineThickness((float)1);

	m_drawDebugRects = true;
}

bool GameObject::getDebugStatus()
{
	return m_drawDebugRects;
}

sf::RectangleShape GameObject::getDebugRectOutline()
{
	return m_debugRectOutline;
}

sf::RectangleShape GameObject::getDebugRectOrigin()
{
	return m_debugRectOrigin;
}

sf::RectangleShape GameObject::getDebugRectPosition()
{
	return m_debugRectPosition;
}

void GameObject::setSprite(sf::Sprite newSprite)
{
	m_sprite = newSprite;
}

void GameObject::setOrigin(sf::Vector2f origin)
{
	m_origin = origin;
	m_sprite.setOrigin(origin);
}

void GameObject::setPosition(sf::Vector2f position)
{
	m_origin = position;
	m_sprite.setOrigin(getBoundingBox().width / 4, getBoundingBox().height / 4);
	m_sprite.setPosition(position);
}