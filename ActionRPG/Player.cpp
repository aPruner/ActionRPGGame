#include "Player.h"

Player::Player(TextureMap *textureMap, Room *room)
{
	m_room = room;
	m_textureMap = textureMap;
	// m_sprite = sf::Sprite(textureMap->getTextureFromFilename(c_playerTextureFilename));
	// setSprite(m_sprite);
	// m_sprite.scale((float) c_playerScalingFactor, (float) c_playerScalingFactor);
	m_idleAnimation = new Animation(textureMap, c_playerIdleAnimName);
	m_sprite = *m_idleAnimation->getFrameSprite();
	m_idleAnimation->startAnimation();
	m_health = c_startingHealth;
	m_speed = c_startingSpeed;
	setOrigin(c_initialPosition);
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

	// TODO: Proper collision detection, with any walls and other GameObjects
	// Collision detection - outer walls only

	// Get the position in the TileMap, and check all 8 positions around the player for intersections
	int xPositionInTileMap = getXPositionInTileMap();
	int yPositionInTileMap = getYPositionInTileMap();

	// Get the global bounds of the debugRect
	sf::FloatRect boundsRect = m_debugRectOutline.getGlobalBounds();

	// Check left boundary
	if (boundsRect.left < 0)
	{
		m_origin.x += timeElapsed * m_speed;
	}

	// Check top boundary
	if (boundsRect.top < 0)
	{
		m_origin.y += timeElapsed * m_speed;
	}

	// Check right boundary
	if (boundsRect.left + boundsRect.width >= c_maxRoomWidthPixels * c_roomScalingFactor)
	{
		m_origin.x -= timeElapsed * m_speed;
	}

	// Check bottom boundary
	if (boundsRect.top + boundsRect.height >= c_maxRoomHeightPixels * c_roomScalingFactor)
	{
		m_origin.y -= timeElapsed * m_speed;
	}

	m_debugRectOutline.setPosition(m_origin);
	m_debugRectOrigin.setPosition(m_origin);

	setPosition(m_origin);

	// where does this go? Does it matter?
	if (m_idleAnimation->isAnimating())
	{
		m_idleAnimation->animate();
		setSprite(*m_idleAnimation->getFrameSprite());
	}
}

// GameObject draw method override
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
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