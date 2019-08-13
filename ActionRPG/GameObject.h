#pragma once
#include <SFML/Graphics.hpp>

// Abstract class from which to derive GameObject classes
class GameObject : sf::Drawable {
private:
	// Sprite for the GameObject
	sf::Sprite sprite;

	// TODO: More GameObject data
	
public:
	// Pure virtual method for updating the game object
	// Must be defined in the subclass
	// params:
	// int timeElapsed: ms elapsed since last draw
	virtual void update(int timeElapsed) = 0;

	// Getter/Setter for the sprite
	sf::Sprite getSprite();
	void setSprite(sf::Sprite newSprite);
	
	// Getter/Setter for the position

	// TODO: figure out API for getPosition
	void getPosition();
	void setPosition();
};