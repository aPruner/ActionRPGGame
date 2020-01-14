#include "Player.h"

Player::Player(TextureMap *textureMap, Room *room)
{
	// Initialize constants object
	m_playerConstants = new PlayerConstants();

	// Initialize the room and textureMap
	m_room = room;
	m_textureMap = textureMap;

	// Initialize animations
	// By default, the player is facing right, the animations need a pointer to this member variable
	// in order to properly know to invert themselves or not
	m_isFacingLeft = false;

	m_idleAnimation = new Animation(
		textureMap,
		m_playerConstants->getPlayerIdleAnimName(m_playerClass),
		m_playerConstants->c_playerAnimScalingFactor,
		m_textureMap->getTextureMapConstants()->c_spriteSheetFilename,
		m_playerConstants->c_playerAnimSpeed,
		&m_isFacingLeft
	);

	m_runAnimation = new Animation(
		textureMap,
		m_playerConstants->getPlayerRunAnimName(m_playerClass),
		m_playerConstants->c_playerAnimScalingFactor,
		m_textureMap->getTextureMapConstants()->c_spriteSheetFilename,
		m_playerConstants->c_playerAnimSpeed,
		&m_isFacingLeft

	);

	m_hitAnimation = new Animation(
		textureMap,
		m_playerConstants->getPlayerHitAnimName(m_playerClass),
		m_playerConstants->c_playerAnimScalingFactor,
		m_textureMap->getTextureMapConstants()->c_spriteSheetFilename,
		m_playerConstants->c_playerAnimSpeed,
		&m_isFacingLeft
	);

	m_weaponIdleAnimation = new Animation(
		textureMap,
		m_playerConstants->c_weaponIdleAnimName,
		m_playerConstants->c_weaponAnimScalingFactor,
		m_textureMap->getTextureMapConstants()->c_weaponAnimSpriteSheetFilename,
		m_playerConstants->c_weaponAnimSpeed,
		&m_isFacingLeft
	);
	m_weaponSwingAnimation = new Animation(
		textureMap,
		m_playerConstants->c_weaponSwingAnimName,
		m_playerConstants->c_weaponAnimScalingFactor,
		m_textureMap->getTextureMapConstants()->c_weaponAnimSpriteSheetFilename,
		m_playerConstants->c_weaponAnimSpeed,
		&m_isFacingLeft
	);

	m_weaponHitboxAnimation = new Animation(
		textureMap,
		m_playerConstants->c_weaponSwingHitboxAnimName,
		m_playerConstants->c_weaponHitboxAnimScalingFactor,
		m_textureMap->getTextureMapConstants()->c_weaponHitboxAnimSpriteSheetFilename,
		m_playerConstants->c_weaponHitboxAnimSpeed,
		&m_isFacingLeft
	);

	// By default, the player will be idle
	m_sprite = *m_idleAnimation->getFrameSprite();
	m_idleAnimation->startAnimation();

	// Weapon stuff
	m_weaponSprite = *m_weaponIdleAnimation->getFrameSprite();
	m_weaponIdleAnimation->startAnimation();

	// Init Origin rect (weapon)
	m_weaponDebugRectOrigin = sf::RectangleShape(sf::Vector2f((float)4, (float)4));
	m_weaponDebugRectOrigin.setFillColor(sf::Color::Yellow);
	m_weaponDebugRectOrigin.setOutlineColor(sf::Color::Yellow);
	m_weaponDebugRectOrigin.setOutlineThickness((float)1);

	m_weaponHitboxAnimSprite = sf::Sprite();

	// Initialize player stats
	initializePlayer();
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
}

// GameObject update method override
void Player::update(float timeElapsed)
{

	sf::Vector2f newPosition = getPosition();
	// Move the Player if necessary
	if (m_moveUpPressed)
	{
		newPosition.y -= timeElapsed * m_speed;
	}

	if (m_moveDownPressed)
	{
		newPosition.y += timeElapsed * m_speed;
	}

	if (m_moveLeftPressed)
	{
		newPosition.x -= timeElapsed * m_speed;
	}

	if (m_moveRightPressed)
	{
		newPosition.x += timeElapsed * m_speed;
	}

	if (m_attackPressed)
	{
		// TODO: Put out the hitbox
	}

	// TODO: Proper collision detection, with any walls and other GameObjects
	// TODO: Since doing the face player left issue, existing hit detection is off. Good thing the system will be rewritten soon anyways!
	// Collision detection - outer walls only
	// Get the position in the TileMap, and check all 8 positions around the player for intersections
	int xPositionInTileMap = getXPositionInTileMap();
	int yPositionInTileMap = getYPositionInTileMap();

	// Get the global bounds of the debugRect
	sf::FloatRect boundsRect = m_debugRectOutline.getGlobalBounds();

	// Check left boundary
	if (boundsRect.left < 0)
	{
		newPosition.x += timeElapsed * m_speed;
	}

	// Check top boundary
	if (boundsRect.top < 0)
	{
		newPosition.y += timeElapsed * m_speed;
	}

	// Check right boundary
	if (boundsRect.left + boundsRect.width >= RoomConstants::c_maxRoomWidthPixels * RoomConstants::c_roomScalingFactor)
	{
		newPosition.x -= timeElapsed * m_speed;
	}

	// Check bottom boundary
	if (boundsRect.top + boundsRect.height >= RoomConstants::c_maxRoomHeightPixels * RoomConstants::c_roomScalingFactor)
	{
		newPosition.y -= timeElapsed * m_speed;
	}

	// Handle animation, only one animation should animate at a time
	if (m_idleAnimation->getIsAnimating())
	{
		m_idleAnimation->animate();
		setSprite(*m_idleAnimation->getFrameSprite());
	}
	else if (m_runAnimation->getIsAnimating())
	{
		m_runAnimation->animate();
		setSprite(*m_runAnimation->getFrameSprite());
	}

	// Handle weapon animation, only one weapon animation should animate at a time
	// Player can move and attack at the same time
	if (m_weaponIdleAnimation->getIsAnimating() && !m_weaponHitboxAnimation->getIsAnimating())
	{
		m_weaponIdleAnimation->animate();
		setWeaponSprite(*m_weaponIdleAnimation->getFrameSprite());
		// Seems kinda hacky but it's probably fine: set the weaponHitboxAnimSprite to the empty Sprite when not animating
		// This will be used for all animations that aren't visible when not animating
		setWeaponHitboxAnimSprite(sf::Sprite());
	}
	else if (m_weaponSwingAnimation->getIsAnimating() && m_weaponHitboxAnimation->getIsAnimating())
	{
		m_weaponSwingAnimation->animate();
		setWeaponSprite(*m_weaponSwingAnimation->getFrameSprite());
		m_weaponHitboxAnimation->animate();
		setWeaponHitboxAnimSprite(*m_weaponHitboxAnimation->getFrameSprite());
	}

	// Move the debug rect as well as the player

	// Move the player
	setPosition(newPosition);

	// Move the debug rect
	// TODO: Constants
	sf::Vector2f debugRectOutlinePosition = sf::Vector2f(newPosition.x - getBoundingBox().width / m_playerConstants->c_halfDenominator, newPosition.y - getBoundingBox().height / m_playerConstants->c_halfDenominator);
	m_debugRectOutline.setPosition(debugRectOutlinePosition);
	m_debugRectOrigin.setPosition(newPosition);

	// Set weapon sprite position
	sf::Vector2f allWeaponSpritesPosition = sf::Vector2f(newPosition.x, newPosition.y + m_playerConstants->c_weaponPositionOffsetY);
	m_weaponSprite.setPosition(allWeaponSpritesPosition);
	m_weaponDebugRectOrigin.setPosition(allWeaponSpritesPosition);

	// Set weapon hitbox anim sprite position
	m_weaponHitboxAnimSprite.setPosition(allWeaponSpritesPosition);
}

// GameObject draw method override
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
	target.draw(m_weaponSprite, states);
	if (m_drawDebugRects)
	{
		target.draw(m_weaponDebugRectOrigin, states);
	}
	target.draw(m_weaponHitboxAnimSprite, states);
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
		if (!m_isFacingLeft)
		{
			setIsFacingLeft(true);
		}
		m_moveLeftPressed = true;
	}

	if (direction == Direction::RIGHT)
	{
		if (m_isFacingLeft)
		{
			setIsFacingLeft(false);
		}
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

void Player::attack()
{
	m_isAttacking = true;
	m_weaponIdleAnimation->stopAnimation();
	m_weaponSwingAnimation->startAnimation();
	m_weaponHitboxAnimation->startAnimation();
}

void Player::stopAttack()
{
	m_isAttacking = false;
	m_weaponSwingAnimation->stopAnimation();
	m_weaponHitboxAnimation->stopAnimation();
	m_weaponIdleAnimation->startAnimation();
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

Animation *Player::getIdleAnimation()
{
	return m_idleAnimation;
}
Animation *Player::getRunAnimation()
{
	return m_runAnimation;
}

Animation *Player::getWeaponIdleAnimation()
{
	return m_weaponIdleAnimation;
}

sf::Sprite Player::getWeaponSprite()
{
	return m_weaponSprite;
}

sf::Sprite Player::getWeaponHitboxAnimSprite()
{
	return m_weaponHitboxAnimSprite;
}

bool Player::getIsFacingLeft()
{
	return m_isFacingLeft;
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

void Player::setWeaponSprite(sf::Sprite weaponSprite)
{
	m_weaponSprite = weaponSprite;
}

void Player::setWeaponHitboxAnimSprite(sf::Sprite weaponHitboxAnimSprite)
{
	m_weaponHitboxAnimSprite = weaponHitboxAnimSprite;
}

void Player::setIsFacingLeft(bool isFacingLeft)
{
	m_isFacingLeft = isFacingLeft;
}