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

	// Whether or not the top part of a wall is drawn on top of this tile
	bool m_isTopWallDrawn;

	// Array of texture coords for this tile type in the dungeon sprite sheet
	sf::Vector2f m_tileTexCoords[RoomConstants::c_vertsInQuad];
	// TODO: Add more appropriate properties here if necessary

public:
	TileProperties(bool isSolid, bool isAnimated, bool drawTopWallOnTop, std::string const& tileTextureName);
	~TileProperties();

	// Getters and Setters
	// Getters
	bool getIsSolid();
	bool getIsAnimated();
	bool getIsTopWallDrawn();
	std::string getTileTextureName();
};

class TileConstants {
public:
	// TileConstants includes constant maps for all of the tile data

	const std::string c_wallTopMidTextureName = "wall_top_mid";

	// Map char -> TileProperties object
	// Room of chars representing tiles in a .txt room file mapped to Tile properties for those tiles
	const std::map<char, TileProperties> c_tilePropertiesMap = {
		{'a', TileProperties(false, false, false, "wall_top_left")},
		{'b', TileProperties(false, false, false, "wall_top_mid")},
		{'c', TileProperties(false, false, false, "wall_top_right")},
		{'d', TileProperties(true, false, false, "wall_left")},
		{'e', TileProperties(true, false, false, "wall_mid")},
		{'f', TileProperties(true, false, false, "wall_right")},
		{'g', TileProperties(true, false, false, "wall_fountain_top")},
		{'h', TileProperties(true, false, false, "wall_hole_1")},
		{'i', TileProperties(true, false, false, "wall_hole_2")},
		{'j', TileProperties(true, false, false, "wall_banner_red")},
		{'k', TileProperties(true, false, false, "wall_banner_blue")},
		{'l', TileProperties(true, false, false, "wall_banner_green")},
		{'m', TileProperties(true, false, false, "wall_banner_yellow")},
		{'n', TileProperties(true, false, false, "column_top")},
		{'o', TileProperties(true, false, false, "column_mid")},
		{'p', TileProperties(true, false, false, "column_base")},
		{'q', TileProperties(true, false, false, "wall_column_top")},
		{'r', TileProperties(true, false, false, "wall_column_mid")},
		{'s', TileProperties(true, false, false, "wall_column_base")},
		{'t', TileProperties(true, false, false, "wall_goo")},
		{'u', TileProperties(true, false, false, "wall_goo_base")},
		{'v', TileProperties(false, false, false, "floor_1")},
		{'w', TileProperties(false, false, false, "floor_2")},
		{'x', TileProperties(false, false, false, "floor_3")},
		{'y', TileProperties(false, false, false, "floor_4")},
		{'z', TileProperties(false, false, false, "floor_5")},
		{'0', TileProperties(false, false, false, "floor_6")},
		{'1', TileProperties(false, false, false, "floor_7")},
		{'2', TileProperties(false, false, false, "floor_8")},
		{'3', TileProperties(true, false, false, "floor_ladder")},
		{'4', TileProperties(true, true, false, "floor_spikes_anim")},
		{'5', TileProperties(true, false, false, "wall_side_top_left")},
		{'6', TileProperties(true, false, false, "wall_side_top_right")},
		{'7', TileProperties(true, false, false, "wall_side_mid_left")},
		{'8', TileProperties(true, false, false, "wall_side_mid_right")},
		{'9', TileProperties(true, false, false, "wall_side_front_left")},
		{'!', TileProperties(true, false, false, "wall_side_front_right")},
		{'@', TileProperties(true, false, false, "wall_corner_top_left")},
		{'#', TileProperties(true, false, false, "wall_corner_top_right")},
		{'$', TileProperties(true, false, false, "wall_corner_left")},
		{'%', TileProperties(true, false, false, "wall_corner_right")},
		{'^', TileProperties(true, false, false, "wall_corner_bottom_left")},
		{'&', TileProperties(true, false, false, "wall_corner_bottom_right")},
		{'*', TileProperties(true, false, false, "wall_corner_front_left")},
		{'(', TileProperties(true, false, false, "wall_corner_front_right")},
		{')', TileProperties(true, false, false, "wall_inner_corner_l_top_left")},
		{'[', TileProperties(true, false, false, "wall_inner_corner_l_top_right")},
		{']', TileProperties(true, false, false, "wall_inner_corner_mid_left")},
		{'{', TileProperties(true, false, false, "wall_inner_corner_mid_right")},
		{'}', TileProperties(true, false, false, "wall_inner_corner_t_top_left")},
		{'-', TileProperties(true, false, false, "wall_inner_corner_t_top_right")},
		{'+', TileProperties(true, false, false, "edge")},
		{'~', TileProperties(true, false, false, "hole")},
		{',', TileProperties(false, false, true, "floor_1")},
		{'\'', TileProperties(false, false, true, "floor_2")},
		{'\"', TileProperties(false, false, true, "floor_3")},
		{'=', TileProperties(false, false, true, "floor_4")},
		{':', TileProperties(false, false, true, "floor_5")},
		{';', TileProperties(false, false, true, "floor_6")},
		{'>', TileProperties(false, false, true, "floor_7")},
		{'<', TileProperties(false, false, true, "floor_8")}
	};
};
