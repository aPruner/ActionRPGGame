#include "Player.h"

Player::Player(TextureMap *textureMap)
{
	textureMap = textureMap;
	sprite = sf::Sprite(textureMap->getTexture(playerTextureFilename));
	setSprite(sprite);
	health = startingHealth;
	setPosition(initialPosition);
}

void Player::update(int timeElapsed)
{

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

void Player::move(Direction direction)
{

}