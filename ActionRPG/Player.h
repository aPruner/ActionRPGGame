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
	const std::string c_playerIdleAnimName = "knight_f_idle_anim";
	const std::string c_playerRunAnimName = "knight_f_run_anim";

	// Player health
	int m_health;

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