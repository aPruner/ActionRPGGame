#pragma once
#include "GameObject.h"

class Player : virtual public GameObject
{
private:
	// Player constants
	const int c_startingHealth = 100;
	const int c_startingSpeed = 200;
	const std::string c_playerTextureFilename = "sprites/player.png";

	// Player health
	int m_health;

	// Player movement speed
	int m_speed;

	// Player movement input flags
	bool m_moveUp_pressed;
	bool m_moveDown_pressed;
	bool m_moveLeft_pressed;
	bool m_moveRight_pressed;

public:
	Player(TextureMap *textureMap);

	// Override for GameObject::update
	void update(float timeElapsed) override;

	// Override for GameObject::draw
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Input handler for moving the player
	void move(Direction direction);

	// Input handler for stopping the player's movement
	void stopMove(Direction direction);

};