#include "GameObject.h"

void GameObject::initDebugRect()
{
	// Init outline rect
	m_debugRectOutline = sf::RectangleShape(sf::Vector2f(getBoundingBox().width, getBoundingBox().height));
	m_debugRectOutline.setFillColor(sf::Color::Transparent);
	m_debugRectOutline.setOutlineColor(sf::Color::Red);
	m_debugRectOutline.setOutlineThickness((float)1);

	// Init Origin rect
	m_debugRectOrigin = sf::RectangleShape(sf::Vector2f((float)4, (float)4));
	m_debugRectOrigin.setFillColor(sf::Color::Green);
	m_debugRectOrigin.setOutlineColor(sf::Color::Green);
	m_debugRectOrigin.setOutlineThickness((float)1); // TODO: Constants

	m_drawDebugRects = true;
}

void GameObject::updateTileCollisions()
{
	// Check for tile map errors, just in case
	std::pair<int, int> positionInTileMap = getPositionInTileMap();
	if (positionInTileMap.first == -1 || positionInTileMap.second == -1)
	{
		return;
	}

	// First, remove tiles that aren't currently colliding if they exist
	auto it = m_tileCollisions->begin();
	while (it < m_tileCollisions->end())
	{
		if (!getIsCollidingWithTile(*it))
		{
			Tile *currentTile = *it;
			currentTile->setIsCollidingWithGameObject(false);
			// Decrement the iterator after erase is executed
			it = m_tileCollisions->erase(it);
		}
		else
		{
			it++;
		}
	}

	// Get all the colliding tiles
	int maxTilesSpannedX = (getBoundingBox().width / RoomConstants::c_tileSideLengthPixels);
	if ((int)getBoundingBox().width % RoomConstants::c_tileSideLengthPixels)
	{
		maxTilesSpannedX++;
	}
	int maxTilesSpannedY = (getBoundingBox().height / RoomConstants::c_tileSideLengthPixels);
	if ((int)getBoundingBox().height % RoomConstants::c_tileSideLengthPixels)
	{
		maxTilesSpannedY++;
	}

	// Add colliding tiles to the tileCollisionArray
	std::pair<int, int> posInTileMap = getPositionInTileMap();
	int xPosInTileMap = posInTileMap.first;
	int maxSpanPosX = xPosInTileMap + maxTilesSpannedX;
	int yPosInTileMap = posInTileMap.second;
	int maxSpanPosY = yPosInTileMap + maxTilesSpannedY;

	for (int i = yPosInTileMap - 1; i < maxSpanPosY; i++)
	{
		for (int j = xPosInTileMap - 1; j < maxSpanPosX; j++)
		{
			if (i >= 0 && i < m_room->getMaxRoomHeightTiles() && j >= 0 && j < m_room->getMaxRoomWidthTiles())
			{
				Tile *currentTile = m_room->getTile(j, i);
				if (getIsCollidingWithTile(currentTile))
				{
					m_tileCollisions->push_back(currentTile);
					currentTile->setIsCollidingWithGameObject(true);
				}
			}
		}
	}
}

void GameObject::updateGameObjectCollisions()
{
	// Loop through tileCollisionArray and check for other gameObjects colliding with those tiles, may need to keep some sort of map of Tile*->vector<GameObject*> in the room
	for (auto it = m_tileCollisions->begin(); it < m_tileCollisions->end(); it++)
	{
	}
}

bool GameObject::getIsCollidingWithTile(Tile *tile)
{
	sf::FloatRect tileBoundingBox = tile->getBoundingBox();
	sf::FloatRect gameObjectBoundingBox = getBoundingBox();
	return tileBoundingBox.intersects(gameObjectBoundingBox);
}

// Getters and Setters
sf::Sprite GameObject::getSprite()
{
	return m_sprite;
}

sf::FloatRect GameObject::getBoundingBox()
{
	return m_sprite.getGlobalBounds();
}

sf::Vector2f GameObject::getPosition()
{
	return m_position;
}

// This getter will always return local (relative) coordinates
sf::Vector2f GameObject::getOrigin()
{
	return m_sprite.getOrigin();
}

// Returns Vector2f(-1, -1) if outside
std::pair<int, int> GameObject::getPositionInTileMap()
{
	if (m_position.x < 0 || m_position.y < 0)
	{
		return std::make_pair(-1, -1);
	}
	int xPositionInTileMap = (int)m_position.x / RoomConstants::c_roomScalingFactor / RoomConstants::c_tileSideLengthPixels;
	int yPositionInTileMap = (int)m_position.y / RoomConstants::c_roomScalingFactor / RoomConstants::c_tileSideLengthPixels;
	return (std::make_pair(xPositionInTileMap, yPositionInTileMap));
}

bool GameObject::getDebugStatus()
{
	return m_drawDebugRects;
}

sf::RectangleShape GameObject::getDebugRectOutline()
{
	return m_debugRectOutline;
}

sf::RectangleShape GameObject::getDebugRectOrigin()
{
	return m_debugRectOrigin;
}

sf::RectangleShape GameObject::getDebugRectPosition()
{
	return m_debugRectPosition;
}

void GameObject::setSprite(sf::Sprite newSprite)
{
	m_sprite = newSprite;
}

void GameObject::setPosition(sf::Vector2f position)
{
	m_position = position;
	// Origin is in local co-ordinates, and getBoundingBox() returns the original width and height of the sprite after scaling,
	// but origin is applied and then scaled (so e.g for the player, width / 4 is width / 2 scaled by the scaling factor (2))
	m_sprite.setOrigin(getBoundingBox().width / 2 / abs(m_sprite.getScale().x), getBoundingBox().height / 2 / abs(m_sprite.getScale().y));
	m_sprite.setPosition(position);

	// Move the debug rects
	sf::Vector2f debugRectOutlinePosition = sf::Vector2f(position.x - getBoundingBox().width / GameObjectConstants::c_halfDenominator, position.y - getBoundingBox().height / GameObjectConstants::c_halfDenominator);
	m_debugRectOutline.setPosition(debugRectOutlinePosition);
	m_debugRectOrigin.setPosition(position);
}