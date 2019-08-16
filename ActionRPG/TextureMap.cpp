#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TextureMap.h"

TextureMap::TextureMap()
{
	m_textureMap = new std::map<std::string, sf::Texture>();
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
		std::istringstream iss(line);
		std::string spriteName;
		int topLeftX, topLeftY, offsetX, offsetY, frames;
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

// TODO: Maybe add a batch loadAllTextures method to load all textures at once in the future