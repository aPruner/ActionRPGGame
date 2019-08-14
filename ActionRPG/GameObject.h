#pragma once
#include <SFML/Graphics.hpp>
#include "TextureMap.h"

// Abstract class from which to derive GameObject classes
class GameObject : public sf::Drawable
{
protected:
	// TextureMap to fetch textures from
	TextureMap *m_textureMap;

	// Sprite for the GameObject
	sf::Sprite m_sprite;

	// Direction enum
	const enum Direction { UP, RIGHT, DOWN, LEFT };

	// Default initial position for GameObjects
	const float c_initialPositionX = 0;
	const float c_initialPositionY = 0;
	const sf::Vector2f c_initialPosition = sf::Vector2f(c_initialPositionX, c_initialPositionY);

public:
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