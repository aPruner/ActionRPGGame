#include "Player.h"

Player::Player(TextureMap *textureMap, Room *room)
{
	m_room = room;
	m_textureMap = textureMap;
	m_sprite = sf::Sprite(textureMap->getTextureFromFilename(c_playerTextureFilename));
	setSprite(m_sprite);
	m_sprite.scale((float) c_playerScalingFactor, (float) c_playerScalingFactor);
	m_health = c_startingHealth;
	m_speed = c_startingSpeed;
	sf::Vector2f initialPosition(
		(float) (c_initialPosition.x + m_sprite.getGlobalBounds().width / 2),
		(float) (c_initialPosition.y + m_sprite.getGlobalBounds().height / 2)
	);
	setOrigin(initialPosition);
	initDebugRect();
}

// GameObject update method override
void Player::update(float timeElapsed)
{
	if (m_moveUp_pressed)
	{
		m_origin.y -= timeElapsed * m_speed;
	}

	if (m_moveDown_pressed)
	{
		m_origin.y += timeElapsed * m_speed;
	}

	if (m_moveLeft_pressed)
	{
		m_origin.x -= timeElapsed * m_speed;
	}

	if (m_moveRight_pressed)
	{
		m_origin.x += timeElapsed * m_speed;
	}

	// Move the debug rect as well as the player
	m_debugRectOutline.setPosition(m_origin);
	m_debugRectOrigin.setPosition(m_origin);

	setPosition(m_origin);
}

// GameObject draw method override
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// target.draw(m_sprite, states);
}

// Set the movement input flags to true based on input directions (pressed)
void Player::move(Direction direction)
{
	if (direction == Direction::UP)
	{
		m_moveUp_pressed = true;
	}

	if (direction == Direction::DOWN)
	{
		m_moveDown_pressed = true;
	}

	if (direction == Direction::LEFT)
	{
		m_moveLeft_pressed = true;
	}

	if (direction == Direction::RIGHT)
	{
		m_moveRight_pressed = true;
	}
}

// Set the movement input flags to false based on input directions (unpressed)
void Player::stopMove(Direction direction)
{
	if (direction == Direction::UP)
	{
		m_moveUp_pressed = false;
	}

	if (direction == Direction::DOWN)
	{
		m_moveDown_pressed = false;
	}

	if (direction == Direction::LEFT)
	{
		m_moveLeft_pressed = false;
	}

	if (direction == Direction::RIGHT)
	{
		m_moveRight_pressed = false;
	}
}