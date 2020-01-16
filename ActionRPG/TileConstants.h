#pragma once
#include <map>
#include <string>

class TileConstants {
	// TileConstants includes constant maps for all of the tile data

	// Map tileTextureName -> isSolid property
	const static std::map<std::string, TileProperties> c_tileQualityMap;


};

// TileProperties is essentially a struct (class) that holds constant properties for each tile type
class TileProperties {
public:
	bool isSolid;
};
