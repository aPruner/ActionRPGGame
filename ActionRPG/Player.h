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
	Player(TextureMap *textureMap, Room *room);

	// Override for GameObject::update
	void update(float timeElapsed) override;

	// Override for GameObject::draw
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Input handler for moving the player
	void move(Direction direction);

	// Input handler for stopping the player's movement
	void stopMove(Direction direction);

};