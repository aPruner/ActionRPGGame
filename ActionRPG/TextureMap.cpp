#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TextureMap.h"

TextureMap::TextureMap()
{
	m_textureMap = new std::map<std::string, sf::Texture>();
	m_textureCoordsMap = new std::map<std::string, std::tuple<sf::Vector2f>>();
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

		// Split the string and deal with it accordingly
		std::istringstream lineStream(line);
		std::vector<std::string> splitLine((std::istream_iterator<std::string>(lineStream)), std::istream_iterator<std::string>());

		std::string textureName;
		int topLeftX, topLeftY, offsetX, offsetY, frames;

		if (splitLine[0] != "#" && splitLine.size() == 5)
		{
			// Not an animation
			textureName = splitLine[0];
			topLeftX = std::stoi(splitLine[1]);
			topLeftY = std::stoi(splitLine[2]);
			offsetX = std::stoi(splitLine[3]);
			offsetY = std::stoi(splitLine[4]);
			
			sf::Vector2f topLeftCoords(topLeftX, topLeftY);
			sf::Vector2f topRightCoords(topLeftX + offsetX, topLeftY);
			sf::Vector2f bottomRightCoords(topLeftX + offsetX, topLeftY + offsetY);
			sf::Vector2f bottomLeftCoords(topLeftX, topLeftY + offsetY);

			std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f> textureCoords(
				topLeftCoords, topRightCoords, bottomRightCoords, bottomLeftCoords
			);

		}
		else if (splitLine[0] != "#" && splitLine.size() == 6)
		{
			// Animation (frames column exists)
			// TODO: loop through and add each frame of the animation to m_textureCoordsMap
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

// TODO: Maybe add a batch loadAllTextures method to load all textures at once in the future