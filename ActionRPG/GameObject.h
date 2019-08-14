#pragma once
#include <SFML/Graphics.hpp>

// Abstract class from which to derive GameObject classes
class GameObject : sf::Drawable
{
private:
	// Sprite for the GameObject
	sf::Sprite sprite;
	
public:
	// Constants used by derived classes
	const enum Direction { UP, RIGHT, DOWN, LEFT };
	const float initialPositionX = 0;
	const float initialPositionY = 0;
	const sf::Vector2f initialPosition = sf::Vector2f(initialPositionX, initialPositionY);

	// Pure virtual method for updating the game object
	// Must be defined in the subclass
	// params:
	// int timeElapsed: ms elapsed since last draw
	virtual void update(int timeElapsed) = 0;

	// Getter/Setter for the sprite
	sf::Sprite getSprite();
	void setSprite(sf::Sprite newSprite);
	
	// Getter/Setter for the position
	sf::FloatRect getPosition();
	void setPosition(sf::Vector2f position);
};