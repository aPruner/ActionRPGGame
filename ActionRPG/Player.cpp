#include "Player.h"

Player::Player(TextureMap *textureMap, Room *room)
{
	// Initialize constants object
	m_playerConstants = new PlayerConstants();

	m_room = room;
	m_textureMap = textureMap;
	// Initialize animations
	m_idleAnimation = new Animation(textureMap, m_playerConstants->getPlayerIdleAnimName(m_playerClass));
	m_runAnimation = new Animation(textureMap, m_playerConstants->getPlayerRunAnimName(m_playerClass));
	m_hitAnimation = new Animation(textureMap, m_playerConstants->getPlayerHitAnimName(m_playerClass));

	// By default, the player will be idle
	m_sprite = *m_idleAnimation->getFrameSprite();
	m_idleAnimation->startAnimation();

	initializePlayer();

	setOrigin(c_initialPosition);
	initDebugRect();
}

// Initialize the player attributes
void Player::initializePlayer()
{
	// TODO: name and class selection (much later)
	m_name = "PlayerNameHere";
	m_playerClass = PlayerConstants::PlayerClass::Knight;
	m_level = PlayerConstants::c_startingLevel;
	m_health = PlayerConstants::c_startingHealth;
	m_speed = PlayerConstants::c_startingSpeed;
	m_strength = PlayerConstants::c_startingStrength;
	m_wisdom = PlayerConstants::c_startingWisdom;
	m_conditioning = PlayerConstants::c_startingConditioning;
	m_agility = PlayerConstants::c_startingAgility;

	// Weapon stuff
	m_weaponTexture = m_textureMap->getTextureFromFilename("sprites/individual_sprites/weapon_knife.png"); // TODO: Make string constant
	m_weaponSprite.setTexture(m_weaponTexture);
	m_weaponSprite.setScale(2, 2); //TODO: constants
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
	if (boundsRect.left + boundsRect.width >= RoomConstants::c_maxRoomWidthPixels * RoomConstants::c_roomScalingFactor)
	{
		m_origin.x -= timeElapsed * m_speed;
	}

	// Check bottom boundary
	if (boundsRect.top + boundsRect.height >= RoomConstants::c_maxRoomHeightPixels * RoomConstants::c_roomScalingFactor)
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


	// TODO: uncomment this when it makes sense
	/*else if (m_attackAnimation->isAnimating())
	{
		m_attackAnimation->animate();
		setSprite(*m_attackAnimation->getFrameSprite());
	}*/

	m_debugRectOutline.setPosition(m_origin);
	m_debugRectOrigin.setPosition(m_origin);

	setPosition(m_origin);

	// Set weapon position

	// TODO: constants where necessary
	m_weaponSprite.setPosition(sf::Vector2f(m_origin.x + 30, m_origin.y + 10));
}

// GameObject draw method override
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
	target.draw(m_weaponSprite, states);
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

// Getters and Setters
PlayerConstants* Player::getPlayerConstants()
{
	return m_playerConstants;
}

std::string& Player::getName()
{
	return m_name;
}

int Player::getLevel()
{
	return m_level;
}

int Player::getHealth()
{
	return m_health;
}

int Player::getMana()
{
	return m_mana;
}

int Player::getSpeed()
{
	return m_speed;
}

int Player::getStrength()
{
	return m_strength;
}

int Player::getWisdom()
{
	return m_wisdom;
}

int Player::getConditioning()
{
	return m_conditioning;
}

int Player::getAgility()
{
	return m_agility;
}

// Setters
void Player::setName(std::string name)
{
	m_name = name;
}

void Player::setLevel(int level)
{
	m_level = level;
}

void Player::setHealth(int health)
{
	m_health = health;
}

void Player::setMana(int mana)
{
	m_mana = mana;
}

void Player::setSpeed(int speed)
{
	m_speed = speed;
}

void Player::setStrength(int strength)
{
	m_strength = strength;
}

void Player::setWisdom(int wisdom)
{
	m_wisdom = wisdom;
}

void Player::setConditioning(int conditioning)
{
	m_conditioning = conditioning;
}

void Player::setAgility(int agility)
{
	m_agility = agility;
}