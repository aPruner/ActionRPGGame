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
	const static std::map<char, std::string> c_roomTxtCharMap;

	const static std::string c_floor1TextureName;
}; 