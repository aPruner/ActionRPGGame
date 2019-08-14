#pragma once
#include "GameObject.h"

class Player : GameObject
{
private:
	int health;

public:
	Player();

	// Override for GameObject::update
	void update(int timeElapsed);

	// Handler for moving the player
	void move(Direction direction);
};