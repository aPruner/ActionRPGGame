#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "RoomConstants.h"

// TileProperties is essentially a struct (class) that holds constant properties for each tile type
// TileProperties will be populated in the above c_tilePropertyMap for each tile texture
// A TileProperties object represents the default properties for each tile type (subject to change in the actual Tile)
class TileProperties {
private:
	std::string m_tileTextureName;
	bool m_isSolid;
	bool m_isAnimated;

	// Array of texture coords for this tile type in the dungeon sprite sheet
	sf::Vector2f m_tileTexCoords[RoomConstants::c_vertsInQuad];
	// TODO: Add more appropriate properties here if necessary

public:
	TileProperties(bool isSolid, bool isAnimated, std::string const& tileTextureName);
	~TileProperties();

	// Getters and Setters
	// Getters
	bool getIsSolid();
	bool getIsAnimated();
	std::string getTileTextureName();

};

class TileConstants {
public:
	// TileConstants includes constant maps for all of the tile data

	// Map tileTextureName -> TileProperties object
	const static std::map<std::string, TileProperties> c_tilePropertyMap;
};
