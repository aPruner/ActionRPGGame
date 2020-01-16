#pragma once
#include <map>
#include <string>

class TileConstants {
public:
	// TileConstants includes constant maps for all of the tile data

	// Map tileTextureName -> isSolid property
	const static std::map<std::string, TileProperties> c_tilePropertyMap;

};

// TileProperties is essentially a struct (class) that holds constant properties for each tile type
// TileProperties will be populated in the above c_tilePropertyMap for each tile texture
class TileProperties {
private:
	std::string m_tileTextureName;
	bool m_isSolid;
	bool m_isAnimated;
	// TODO: Add more appropriate properties here if necessary

public:
	TileProperties(bool isSolid, bool isAnimated, std::string tileTextureName);
	~TileProperties();

	// Getters and Setters
	// Getters
	bool getIsSolid();
	bool getIsAnimated();
	std::string getTileTextureName();

};
