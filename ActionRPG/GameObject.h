#pragma once
#include <SFML/Graphics.hpp>

// Abstract class from which to derive GameObject classes
class GameObject : sf::Drawable
{
private:
	// TODO: private GameObject data (if applicable)

public:
	// Constants used by derived classes
	const enum Direction { UP, RIGHT, DOWN, LEFT };
	const float initialPositionX = 0;
	const float initialPositionY = 0;
	const sf::Vector2f initialPosition = sf::Vector2f(initialPositionX, initialPositionY);

	// Sprite for the GameObject
	sf::Sprite sprite;

	// Pure virtual method for updating the game object
	// Must be defined in the derived class
	// params:
	// int timeElapsed: ms elapsed since last draw
	virtual void update(int timeElapsed) = 0;

	// Pure virtual method for drawing the game object
	// Must be defined in the derived class
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	// Getter/Setter for the sprite
	sf::Sprite getSprite();
	void setSprite(sf::Sprite newSprite);
	
	// Getter/Setter for the position
	// NOTE: setPosition assumes the sprite has already been set
	sf::FloatRect getPosition();
	void setPosition(sf::Vector2f position);
};