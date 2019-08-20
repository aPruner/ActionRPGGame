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
	m_center = position;
	m_sprite.setPosition(position);
}

void GameObject::setCenter(sf::Vector2f position)
{
	m_center = position;
	m_sprite.setOrigin(position);
}

sf::Vector2f GameObject::getCenter()
{
	return m_center;
}

int GameObject::getXPositionInTileMap()
{
	return (int) m_center.x / c_roomScalingFactor / c_tileSideLengthPixels;
}

int GameObject::getYPositionInTileMap()
{
	return (int) m_center.y / c_roomScalingFactor / c_tileSideLengthPixels;
}

void GameObject::setDebugRect()
{
	m_debugRect = sf::RectangleShape(sf::Vector2f(getPosition().width, getPosition().height));
	m_debugRect.setPosition(getCenter());
	m_debugRect.setFillColor(sf::Color::Transparent);
	m_debugRect.setOutlineColor(sf::Color::Red);
	m_debugRect.setOutlineThickness((float)1);
	m_drawDebugRect = true;
}

bool GameObject::getDebugStatus()
{
	return m_drawDebugRect;
}

sf::RectangleShape GameObject::getDebugRectangleShape()
{
	return m_debugRect;
}