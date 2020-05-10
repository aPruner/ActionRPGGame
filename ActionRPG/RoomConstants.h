#pragma once
#include <map>
#include <string>

class RoomConstants {
public:
	// Room Constants

	// TODO: Remove these values and let the dungeon reader set them as member variables
	const static int c_maxRoomWidthPixels = 256;
	const static int c_maxRoomHeightPixels = 256;

	// TODO: This should be a TileConstant, but since it's used to calculate the below values, leave it here for now
	const static int c_tileSideLengthPixels = 16;
	const static int c_maxRoomWidthTiles = c_maxRoomWidthPixels / c_tileSideLengthPixels;
	const static int c_maxRoomHeightTiles = c_maxRoomHeightPixels / c_tileSideLengthPixels;
	const static int c_vertsInQuad = 4;
	const static int c_roomScalingFactor = 2;
	const static int c_roomTileMapSize = c_maxRoomWidthTiles * c_maxRoomHeightTiles;
	const static size_t c_roomVASize = c_roomTileMapSize * c_vertsInQuad;

	const static std::string c_roomFilename;
}; 