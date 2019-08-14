#include "Player.h"

Player::Player(TextureMap *textureMap)
{
	m_textureMap = textureMap;
	m_sprite = sf::Sprite(textureMap->getTexture(c_playerTextureFilename));
	setSprite(m_sprite);
	m_health = c_startingHealth;
	setPosition(c_initialPosition);
}

void Player::update(int timeElapsed)
{
	
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}

void Player::move(Direction direction)
{

}