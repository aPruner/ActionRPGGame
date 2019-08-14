#include "Player.h"

Player::Player()
{
	sf::Sprite sprite;
	sprite.setTexture(TextureMap::getTexture(playerTextureFilename));
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