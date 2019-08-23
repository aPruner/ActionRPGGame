#pragma once
#include "GameObject.h"
#include "Room.h"
#include "Animation.h"

class Player : virtual public GameObject
{
private:
	// Player constants
	const static int c_startingHealth = 100;
	const static int c_startingSpeed = 200;
	const static int c_playerScalingFactor = 2;
	// const std::string c_playerTextureFilename = "sprites/player.png";
	const std::string c_playerIdleAnimName = "elf_f_idle_anim";

	// Player health
	int m_health;

	// Player movement speed
	int m_speed;

	// Player movement input flags
	bool m_moveUp_pressed;
	bool m_moveDown_pressed;
	bool m_moveLeft_pressed;
	bool m_moveRight_pressed;

	// Instance of the room
	Room *m_room;

	// Player idle animation
	Animation *m_idleAnimation;

public:
	Player(TextureMap *textureMapm, Room *room);

	// Override for GameObject::update
	void update(float timeElapsed) override;

	// Override for GameObject::draw
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Input handler for moving the player
	void move(Direction direction);

	// Input handler for stopping the player's movement
	void stopMove(Direction direction);

};