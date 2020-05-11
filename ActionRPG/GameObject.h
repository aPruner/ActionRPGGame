#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "TextureMap.h"
#include "RoomConstants.h"
#include "GameObjectConstants.h"
#include "Room.h"

// Abstract class from which to derive GameObject classes
class GameObject : public sf::Drawable
{
protected:
	// TextureMap to fetch textures from
	TextureMap *m_textureMap;

	// Instance of the room
	Room *m_room;

	// Sprite for the GameObject
	sf::Sprite m_sprite;

	// TODO: Refactor m_debugRectOutline to be a hurtbox
	// Rectangle drawables for debugging 
	sf::RectangleShape m_debugRectOutline; // (outline of GameObject)
	sf::RectangleShape m_debugRectOrigin; // (origin of GameObject)
	sf::RectangleShape m_debugRectPosition; // (position of GameObject)

	// Flag for whether or not to draw debug rectangles
	bool m_drawDebugRects;

	// Set and color the debug rect
	void initDebugRect();

	// Position (global coordinates) of the GameObject
	sf::Vector2f m_position;

	// Array of tile pointers that this GameObject currently collides with
	std::vector<Tile *> *m_collisionArray;

	// Fill the collision array appropriately
	void updateCollisionArray();
	
	// Check (with axis-aligned bounding boxes) if this GameObject collides with the current tile
	bool getIsCollidingWithTile(Tile *tile);

public:
	// Direction enum
	const enum class Direction { UP, RIGHT, DOWN, LEFT };

	// Pure virtual method for updating the game object
	// Must be defined in the derived class
	// params:
	// int timeElapsed: ms elapsed since last draw
	virtual void update(float timeElapsed) = 0;

	// Pure virtual method for drawing the game object
	// Must be defined in the derived class
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	
	// Getters and Setters
	// Getters
	sf::Sprite getSprite();

	// Get the bounding box (global bounds) of the GameObject
	sf::FloatRect getBoundingBox();

	// Get the position (global coordinates) of the GameObject
	sf::Vector2f getPosition();

	// Get the origin (center in local coordinates) of the GameObject - kinda useless
	sf::Vector2f getOrigin();

	// Return position of this GameObject in the tile map (Room position)
	// as a std::pair of (x, y)
	std::pair<int, int> getPositionInTileMap();

	// Debug getters
	bool getDebugStatus();
	sf::RectangleShape getDebugRectOutline();
	sf::RectangleShape getDebugRectOrigin();
	sf::RectangleShape getDebugRectPosition();

	// Setters
	void setSprite(sf::Sprite newSprite);

	// Sets the position of the GameObject in global coordinates, and also sets the origin to the center of the GameObject (for inversions)
	void setPosition(sf::Vector2f position);
};