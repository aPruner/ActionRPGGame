#pragma once
#include "GameObject.h"

class Player : virtual public GameObject
{
private:
	int m_health;
	const int c_startingHealth = 100;
	const std::string c_playerTextureFilename = "sprites/player.png";

public:
	Player(TextureMap *textureMap);

	// Override for GameObject::update
	void update(int timeElapsed) override;

	// Override for GameObject::draw
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Handler for moving the player
	void move(Direction direction);
};