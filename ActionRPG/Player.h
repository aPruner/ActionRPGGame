#pragma once
#include "GameObject.h"
#include "TextureMap.h"

class Player : GameObject
{
private:
	int health;
	const int startingHealth = 100;
	const std::string playerTextureFilename = "sprites/player.png";

public:
	Player();

	// Override for GameObject::update
	virtual void update(int timeElapsed) override;

	// Override for GameObject::draw
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Handler for moving the player
	void move(Direction direction);
};