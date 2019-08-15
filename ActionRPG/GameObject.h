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

	// Center (position) of the GameObject
	// TODO: Clarify if this should be called center or position
	sf::Vector2f m_center;

	// Default initial position for GameObjects
	const float c_initialPositionX = 0;
	const float c_initialPositionY = 0;
	const sf::Vector2f c_initialPosition = sf::Vector2f(c_initialPositionX, c_initialPositionY);

public:
	// Direction enum
	const enum Direction { UP, RIGHT, DOWN, LEFT };

	// Pure virtual method for updating the game object
	// Must be defined in the derived class
	// params:
	// int timeElapsed: ms elapsed since last draw
	virtual void update(float timeElapsed) = 0;

	// Pure virtual method for drawing the game object
	// Must be defined in the derived class
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	// Getter/Setter for the sprite
	sf::Sprite getSprite();
	void setSprite(sf::Sprite newSprite);
	
	// Get the position (global bounds) of the GameObject
	sf::FloatRect getPosition();
	void setPosition(sf::Vector2f);

	// Getter/Setter for the center of the GameObject
	sf::Vector2f getCenter();
	void setCenter(sf::Vector2f position);
};