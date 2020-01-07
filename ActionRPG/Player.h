#pragma once
#include "GameObject.h"
#include "Room.h"
#include "Animation.h"
#include "PlayerConstants.h"

class Player : virtual public GameObject
{
private:
	// Player Constants object
	PlayerConstants *m_playerConstants;

	// Player Class - defines abilities
	PlayerConstants::PlayerClass m_playerClass;

	// Player level
	int m_level;

	// Player name
	std::string m_name;

	// Player Attributes - effects subject to change
	// Strength: increases raw melee attack damage, slightly increases health pool
	int m_strength;
	// Wisdom: increases spellcasting damage and healing, significantly increases mana pool
	int m_wisdom;
	// Conditioning: significantly increases health pool, slightly increases attack speed
	int m_conditioning;
	// Agility: Significantly increases attack speed, slightly increases movement speed
	int m_agility;

	// Player health
	int m_health;

	// Player mana
	int m_mana;

	// Player movement speed
	int m_speed;

	// Player movement input flags
	bool m_moveUpPressed;
	bool m_moveDownPressed;
	bool m_moveLeftPressed;
	bool m_moveRightPressed;

	// Instance of the room
	Room *m_room;

	// Player animations
	Animation *m_idleAnimation;
	Animation *m_runAnimation;
	Animation *m_hitAnimation;

	// TODO: figure out how to implement this, will be complicated because it's not built into the sprite sheet
	Animation *m_attackAnimation;

	//TODO: Write a weapon class to that will hold extra data about the weapon, but for now, just a sprite will do
	sf::Sprite m_weaponSprite;
	sf::Texture m_weaponTexture;

	void initializePlayer();

public:
	Player(TextureMap *textureMap, Room *room);

	// Override for GameObject::update
	void update(float timeElapsed) override;

	// Override for GameObject::draw
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Input handler for moving the player
	void move(Direction direction);

	// Input handler for stopping the player's movement
	void stopMove(Direction direction);

	// Getters and Setters
	// Getters
	PlayerConstants *getPlayerConstants();
	std::string& getName();
	int getLevel();
	int getHealth();
	int getMana();
	int getSpeed();
	int getStrength();
	int getWisdom();
	int getConditioning();
	int getAgility();

	// Setters
	void setName(std::string name);
	void setLevel(int level);
	void setHealth(int health);
	void setMana(int mana);
	void setSpeed(int speed);
	void setStrength(int strength);
	void setWisdom(int wisdom);
	void setConditioning(int conditioning);
	void setAgility(int agility);

};