#pragma once
#include <map>
#include <string>

class RoomConstants {
public:
	// Room Constants
	const static int c_maxRoomWidthPixels = 256;
	const static int c_maxRoomHeightPixels = 256;
	const static int c_tileSideLengthPixels = 16;
	const static int c_maxRoomWidthTiles = c_maxRoomWidthPixels / c_tileSideLengthPixels;
	const static int c_maxRoomHeightTiles = c_maxRoomHeightPixels / c_tileSideLengthPixels;
	const static int c_vertsInQuad = 4;
	const static int c_roomScalingFactor = 2;
	const static int c_roomTileMapSize = c_maxRoomWidthTiles * c_maxRoomHeightTiles;
	const static size_t c_roomVASize = c_roomTileMapSize * c_vertsInQuad;

	// Room of chars representing tiles in a .txt room file mapped to texture names for those tiles
	const std::map<char, std::string> c_roomTxtCharMap = {
		{'a', "wall_top_left"},
		{'b', "wall_top_mid"},
		{'c', "wall_top_right"},
		{'d', "wall_left"},
		{'e', "wall_mid"},
		{'f', "wall_right"},
		{'g', "wall_fountain_top"},
		{'h', "wall_hole_1"},
		{'i', "wall_hole_2"},
		{'j', "wall_banner_red"},
		{'k', "wall_banner_blue"},
		{'l', "wall_banner_green"},
		{'m', "wall_banner_yellow"},
		{'n', "column_top"},
		{'o', "column_mid"},
		{'p', "column_base"},
		{'q', "wall_column_top"},
		{'r', "wall_column_mid"},
		{'s', "wall_column_base"},
		{'t', "wall_goo"},
		{'u', "wall_goo_base"},
		{'v', "floor_1"},
		{'w', "floor_2"},
		{'x', "floor_3"},
		{'y', "floor_4"},
		{'z', "floor_5"},
		{'0', "floor_6"},
		{'1', "floor_7"},
		{'2', "floor_8"},
		{'3', "floor_ladder"},
		{'4', "floor_spikes_anim"},
		{'5', "wall_side_top_left"},
		{'6', "wall_side_top_right"},
		{'7', "wall_side_mid_left"},
		{'8', "wall_side_mid_right"},
		{'9', "wall_side_front_left"},
		{'!', "wall_side_front_right"},
		{'@', "wall_corner_top_left"},
		{'#', "wall_corner_top_right"},
		{'$', "wall_corner_left"},
		{'%', "wall_corner_right"},
		{'^', "wall_corner_bottom_left"},
		{'&', "wall_corner_bottom_right"},
		{'9', "wall_corner_front_left"},
		{'*', "wall_corner_front_right"},
		{'(', "wall_inner_corner_l_top_left"},
		{')', "wall_inner_corner_l_top_right"},
		{'[', "wall_inner_corner_mid_left"},
		{']', "wall_inner_corner_mid_right"},
		{'-', "wall_inner_corner_t_top_left"},
		{'+', "wall_inner_corner_t_top_right"},
		{'\'', "edge"},
		{'~', "hole"}
	};

	const std::string c_floor1TextureName = "floor_1";

}; 