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
	m_sprite.setPosition(position);
}