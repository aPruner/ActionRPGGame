#include "GameObject.h"

sf::Sprite GameObject::getSprite()
{
	return sprite;
}

void GameObject::setSprite(sf::Sprite newSprite)
{
	sprite = newSprite;
}

sf::FloatRect GameObject::getPosition()
{
	return sprite.getGlobalBounds();
}

void GameObject::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}