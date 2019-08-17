#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TextureMap.h"

TextureMap::TextureMap()
{
	m_textureMap = new std::map<std::string, sf::Texture>();
	m_spriteSheetTextureMap = new std::map<std::string, sf::Texture>();
	m_spriteSheet.loadFromFile(c_spriteSheetFilename);
	loadTexturesFromTileList(c_tileListFilename);
}

TextureMap::~TextureMap()
{
	delete m_textureMap;
}

void TextureMap::loadTexturesFromTileList(std::string const& tileListFilename)
{
	std::ifstream tileListFile;
	tileListFile.open(tileListFilename);

	std::string line;
	while (std::getline(tileListFile, line))
	{
		std::istringstream lineStream(line);
		std::vector<std::string> splitLine((std::istream_iterator<std::string>(lineStream)), std::istream_iterator<std::string>());

		std::string textureName;
		int topLeftX, topLeftY, width, height;
		// TODO: deal with frames and size == 6 case
		// int frames;

		if (splitLine[0] != "#" && splitLine.size() == 5)
		{
			// Not an animation (there is no frames column)
			textureName = splitLine[0];
			topLeftX = std::stoi(splitLine[1]);
			topLeftY = std::stoi(splitLine[2]);
			width = std::stoi(splitLine[3]);
			height = std::stoi(splitLine[4]);

			// A bit of a hack: since there is no way to create a texture via IntRect slicing of a sprite sheet,
			// create an intermediate sprite and grab the texture from that sprite to stick in the map
			sf::Sprite sprite(m_spriteSheet, sf::IntRect(topLeftX, topLeftY, width, height));
			sf::Texture newTexture(*sprite.getTexture());
			m_spriteSheetTextureMap->insert(std::pair<std::string, sf::Texture>(textureName, newTexture));

		}
		else if (splitLine[0] != "#" && splitLine.size() == 6)
		{
			// Animation (frames column exists)
			// TODO: loop through and add each frame of the animation to m_textureCoordsMap
			continue;
		}
	}
}

sf::Texture& TextureMap::getTextureFromFilename(std::string const& filename)
{
	auto it = m_textureMap->find(filename);
	if (it != m_textureMap->end())
	{
		return it->second;
	}
	else
	{
		sf::Texture texture;
		texture.loadFromFile(filename);
		m_textureMap->insert(std::pair<std::string, sf::Texture>(filename, texture));
		return m_textureMap->at(filename);
	}
}

// Assumes textureName exists in the map, otherwise returns a new dummy texture
sf::Texture& TextureMap::getSpriteSheetTextureFromTextureName(std::string const& textureName)
{
	auto it = m_spriteSheetTextureMap->find(textureName);
	if (it != m_spriteSheetTextureMap->end())
	{
		return it->second;
	}

	// If textureName doesn't exist in the map, return a new dummy texture
	sf::Texture *texture = new sf::Texture();
	return *texture;
}