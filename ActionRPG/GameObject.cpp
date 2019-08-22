#include "GameObject.h"

sf::Sprite GameObject::getSprite()
{
	return m_sprite;
}

void GameObject::setSprite(sf::Sprite newSprite)
{
	m_sprite = newSprite;
}

sf::FloatRect GameObject::getPosition()
{
	return m_sprite.getGlobalBounds();
}

void GameObject::setPosition(sf::Vector2f position)
{
	m_origin = position;
	m_sprite.setPosition(position);
}

void GameObject::setOrigin(sf::Vector2f position)
{
	m_origin = position;
	m_sprite.setOrigin(position);
}

sf::Vector2f GameObject::getOrigin()
{
	return m_origin;
}

// Returns -1 if outside
int GameObject::getXPositionInTileMap()
{
	int xPositionInTileMap = (int) m_origin.x / c_roomScalingFactor / c_tileSideLengthPixels;
	if (m_origin.x < 0)
	{
		return -1;
	}
	return xPositionInTileMap;
}

// Returns -1 if outside
int GameObject::getYPositionInTileMap()
{
	int yPositionInTileMap = (int) m_origin.y / c_roomScalingFactor / c_tileSideLengthPixels;
	if (m_origin.y < 0)
	{
		return -1;
	}
	return yPositionInTileMap;
}

void GameObject::initDebugRect()
{
	// Init outline rect
	m_debugRectOutline = sf::RectangleShape(sf::Vector2f(getPosition().width, getPosition().height));
	m_debugRectOutline.setPosition(getOrigin());
	m_debugRectOutline.setFillColor(sf::Color::Transparent);
	m_debugRectOutline.setOutlineColor(sf::Color::Red);
	m_debugRectOutline.setOutlineThickness((float)1);

	// Init Origin rect
	m_debugRectOrigin = sf::RectangleShape(sf::Vector2f((float)4, (float)4));
	m_debugRectOrigin.setPosition(getOrigin());
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