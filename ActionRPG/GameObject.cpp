#include "GameObject.h"

void GameObject::initDebugRect()
{
	// Init outline rect
	m_debugRectOutline = sf::RectangleShape(sf::Vector2f(getBoundingBox().width, getBoundingBox().height));
	m_debugRectOutline.setOrigin(getPosition());
	m_debugRectOutline.setFillColor(sf::Color::Transparent);
	m_debugRectOutline.setOutlineColor(sf::Color::Red);
	m_debugRectOutline.setOutlineThickness((float)1);

	// Init Origin rect
	m_debugRectOrigin = sf::RectangleShape(sf::Vector2f((float)4, (float)4));
	m_debugRectOrigin.setOrigin(getPosition());
	m_debugRectOrigin.setFillColor(sf::Color::Green);
	m_debugRectOrigin.setOutlineColor(sf::Color::Green);
	m_debugRectOrigin.setOutlineThickness((float)1);

	m_drawDebugRects = true;
}

void GameObject::updateCollisionArray()
{
	// Do math here to update the collision array
}

// Getters and Setters
sf::Sprite GameObject::getSprite()
{
	return m_sprite;
}

sf::FloatRect GameObject::getBoundingBox()
{
	return m_sprite.getGlobalBounds();
}

sf::Vector2f GameObject::getPosition()
{
	return m_position;
}

// This getter is mostly useless because it will always return the same value in local coordinates
sf::Vector2f GameObject::getOrigin()
{
	return m_sprite.getOrigin();
}

// Returns -1 if outside
int GameObject::getXPositionInTileMap()
{
	int xPositionInTileMap = (int) m_position.x / RoomConstants::c_roomScalingFactor / RoomConstants::c_tileSideLengthPixels;
	if (m_position.x < 0)
	{
		return -1;
	}
	return xPositionInTileMap;
}

// Returns -1 if outside
int GameObject::getYPositionInTileMap()
{
	int yPositionInTileMap = (int) m_position.y / RoomConstants::c_roomScalingFactor / RoomConstants::c_tileSideLengthPixels;
	if (m_position.y < 0)
	{
		return -1;
	}
	return yPositionInTileMap;
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

void GameObject::setPosition(sf::Vector2f position)
{
	m_position = position;
	// Origin is in local co-ordinates, and getBoundingBox() returns the original width and height of the sprite after scaling,
	// but origin is applied and then scaled (so e.g for the player, width / 4 is width / 2 scaled by the scaling factor (2))
	m_sprite.setOrigin(getBoundingBox().width / 2 / abs(m_sprite.getScale().x), getBoundingBox().height / 2 / abs(m_sprite.getScale().y));
	m_sprite.setPosition(position);
}