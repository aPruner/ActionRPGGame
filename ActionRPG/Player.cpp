#include "Player.h"

Player::Player(TextureMap *textureMap, Room *room)
{
	m_room = room;
	m_textureMap = textureMap;
	// Initialize animations
	m_idleAnimation = new Animation(textureMap, c_playerIdleAnimName);
	m_runAnimation = new Animation(textureMap, c_playerRunAnimName);

	// By default, the player will be idle
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

	if (m_moveUpPressed)
	{
		m_origin.y -= timeElapsed * m_speed;
	}

	if (m_moveDownPressed)
	{
		m_origin.y += timeElapsed * m_speed;
	}

	if (m_moveLeftPressed)
	{
		m_origin.x -= timeElapsed * m_speed;
	}

	if (m_moveRightPressed)
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

	// Handle animation, only one animation should animate at a time
	if (m_idleAnimation->isAnimating())
	{
		m_idleAnimation->animate();
		setSprite(*m_idleAnimation->getFrameSprite());
	}
	else if (m_runAnimation->isAnimating())
	{
		m_runAnimation->animate();
		setSprite(*m_runAnimation->getFrameSprite());
	}

	m_debugRectOutline.setPosition(m_origin);
	m_debugRectOrigin.setPosition(m_origin);

	setPosition(m_origin);
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
		m_moveUpPressed = true;
	}

	if (direction == Direction::DOWN)
	{
		m_moveDownPressed = true;
	}

	if (direction == Direction::LEFT)
	{
		m_moveLeftPressed = true;
	}

	if (direction == Direction::RIGHT)
	{
		m_moveRightPressed = true;
	}
	m_idleAnimation->stopAnimation();
	m_runAnimation->startAnimation();
}

// Set the movement input flags to false based on input directions (unpressed)
void Player::stopMove(Direction direction)
{
	if (direction == Direction::UP)
	{
		m_moveUpPressed = false;
	}

	if (direction == Direction::DOWN)
	{
		m_moveDownPressed = false;
	}

	if (direction == Direction::LEFT)
	{
		m_moveLeftPressed = false;
	}

	if (direction == Direction::RIGHT)
	{
		m_moveRightPressed = false;
	}

	if (!m_moveDownPressed && !m_moveUpPressed && !m_moveLeftPressed && !m_moveRightPressed)
	{
		m_runAnimation->stopAnimation();
		m_idleAnimation->startAnimation();
	}
}