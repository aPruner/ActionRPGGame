#pragma once
#include <SFML/Graphics.hpp>
#include "TextureMap.h"

// Abstract class from which to derive GameObject classes
class GameObject : public sf::Drawable
{
protected:
	// TODO: reduce duplicate code
	const static int c_maxRoomWidthPixels = 256;
	const static int c_maxRoomHeightPixels = 256;
	const static int c_tileSideLengthPixels = 16;
	const static int c_maxRoomWidthTiles = c_maxRoomWidthPixels / c_tileSideLengthPixels;
	const static int c_maxRoomHeightTiles = c_maxRoomHeightPixels / c_tileSideLengthPixels;
	const static int c_roomScalingFactor = 2;

	// GameObject constants
	const float c_initialPositionX = 0;
	const float c_initialPositionY = 0;
	const sf::Vector2f c_initialPosition = sf::Vector2f(c_initialPositionX, c_initialPositionY);

	// TextureMap to fetch textures from
	TextureMap *m_textureMap;

	// Sprite for the GameObject
	sf::Sprite m_sprite;

	// Rectangle drawables for debugging 
	sf::RectangleShape m_debugRectOutline; // (outline of GameObject)
	sf::RectangleShape m_debugRectOrigin; // (origin of GameObject)

	bool m_drawDebugRects;

	// Set and color the debugging rect
	void initDebugRect();

	// Origin (position) of the GameObject
	sf::Vector2f m_origin;

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

	// Getter/Setter for the origin of the GameObject
	sf::Vector2f getOrigin();
	void setOrigin(sf::Vector2f position);

	// Return x or y position of this GameObject in the tile map
	int getXPositionInTileMap();
	int getYPositionInTileMap();
	
	// Debug helper methods
	bool getDebugStatus();
	sf::RectangleShape getDebugRectOutline();
	sf::RectangleShape getDebugRectOrigin();
};