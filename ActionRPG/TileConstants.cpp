#include "TileConstants.h"

// TODO: Be aware of wall top part edge case, it may (seemingly) need to be solid if it is part of a top (back) wall,
// but it shouldn't be solid as part of a bottom (front) wall
std::map<std::string, TileProperties> c_tilePropertyMap = {
	{"wall_top_left", TileProperties(false, false, "wall_top_left")},
	{"wall_top_mid", TileProperties(false, false, "wall_top_mid")},
	{"wall_top_right", TileProperties(false, false, "wall_top_right")},
	{"wall_left", TileProperties(true, false, "wall_left")},
	{"wall_mid", TileProperties(true, false, "wall_mid")},
	{"wall_right", TileProperties(true, false, "wall_right")},
	{"wall_fountain_top", TileProperties(true, false, "wall_fountain_top")},
	{"wall_hole_1", TileProperties(true, false, "wall_hole_1")},
	{"wall_hole_2", TileProperties(true, false, "wall_hole_2")},
	{"wall_banner_red", TileProperties(true, false, "wall_banner_red")},
	{"wall_banner_blue", TileProperties(true, false, "wall_banner_blue")},
	{"wall_banner_green", TileProperties(true, false, "wall_banner_green")},
	{"wall_banner_yellow", TileProperties(true, false, "wall_banner_yellow")},
	{"column_top", TileProperties(true, false, "column_top")},
	{"column_mid", TileProperties(true, false, "column_mid")},
	{"column_base", TileProperties(true, false, "column_base")},
	{"wall_column_top", TileProperties(true, false, "wall_column_top")},
	{"wall_column_mid", TileProperties(true, false, "wall_column_mid")},
	{"wall_column_base", TileProperties(true, false, "wall_column_base")},
	{"wall_goo", TileProperties(true, false, "wall_goo")},
	{"wall_goo_base", TileProperties(true, false, "wall_goo_base")},
	{"floor_1", TileProperties(false, false, "floor_1")},
	{"floor_2", TileProperties(false, false, "floor_2")},
	{"floor_3", TileProperties(false, false, "floor_3")},
	{"floor_4", TileProperties(false, false, "floor_4")},
	{"floor_5", TileProperties(false, false, "floor_5")},
	{"floor_6", TileProperties(false, false, "floor_6")},
	{"floor_7", TileProperties(false, false, "floor_7")},
	{"floor_8", TileProperties(false, false, "floor_8")},
	{"floor_ladder", TileProperties(true, false, "floor_ladder")},
	{"floor_spikes_anim", TileProperties(true, true, "floor_spikes_anim")},
	{"wall_side_top_left", TileProperties(true, false, "wall_side_top_left")},
	{"wall_side_top_right", TileProperties(true, false, "wall_side_top_right")},
	{"wall_side_mid_left", TileProperties(true, false, "wall_side_mid_left")},
	{"wall_side_mid_right", TileProperties(true, false, "wall_side_mid_right")},
	{"wall_side_front_left", TileProperties(true, false, "wall_side_front_left")},
	{"wall_side_front_right", TileProperties(true, false, "wall_side_front_right")},
	{"wall_corner_top_left", TileProperties(true, false, "wall_corner_top_left")},
	{"wall_corner_top_right", TileProperties(true, false, "wall_corner_top_right")},
	{"wall_corner_left", TileProperties(true, false, "wall_corner_left")},
	{"wall_corner_right", TileProperties(true, false, "wall_corner_right")},
	{"wall_corner_bottom_left", TileProperties(true, false, "wall_corner_bottom_left")},
	{"wall_corner_bottom_right", TileProperties(true, false, "wall_corner_bottom_right")},
	{"wall_corner_front_left", TileProperties(true, false, "wall_corner_front_left")},
	{"wall_corner_front_right", TileProperties(true, false, "wall_corner_front_right")},
	{"wall_inner_corner_l_top_left", TileProperties(true, false, "wall_inner_corner_l_top_left")},
	{"wall_inner_corner_l_top_right", TileProperties(true, false, "wall_inner_corner_l_top_right")},
	{"wall_inner_corner_mid_left", TileProperties(true, false, "wall_inner_corner_mid_left")},
	{"wall_inner_corner_mid_right", TileProperties(true, false, "wall_inner_corner_mid_right")},
	{"wall_inner_corner_t_top_left", TileProperties(true, false, "wall_inner_corner_t_top_left")},
	{"wall_inner_corner_t_top_right", TileProperties(true, false, "wall_inner_corner_t_top_right")},
	{"edge", TileProperties(true, false, "edge")},
	{"hole", TileProperties(true, false, "hole")}
};

TileProperties::TileProperties(bool isSolid, bool isAnimated, std::string tileTextureName)
{
	m_isSolid = isSolid;
	m_isAnimated = isAnimated;
	m_tileTextureName = tileTextureName;
}

TileProperties::~TileProperties()
{
}

bool TileProperties::getIsSolid()
{
	return m_isSolid;
}

bool TileProperties::getIsAnimated()
{
	return m_isAnimated;
}

std::string TileProperties::getTileTextureName()
{
	return m_tileTextureName;
}