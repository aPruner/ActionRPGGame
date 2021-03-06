#include "TextureMap.h"

TextureMap::TextureMap()
{
	m_textureMapConstants = new TextureMapConstants();

	m_textureMap = new std::map<std::string, sf::Texture>();
	m_spriteSheetVecTupleTextureMap = new std::map<std::string, std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f>>();
	m_spriteSheetAnimTextureMap = new std::map<std::string, std::tuple<int, int, int, int, int>>();
	m_spriteSheetNonAnimTextureMap = new std::map<std::string, std::tuple<int, int, int, int>>();
	m_spriteSheetMap = new std::map<std::string, sf::Texture>();

	addSpriteSheet(m_textureMapConstants->c_spriteSheetFilename);
	addSpriteSheet(m_textureMapConstants->c_weaponAnimSpriteSheetFilename);
	addSpriteSheet(m_textureMapConstants->c_weaponHitboxAnimSpriteSheetFilename);

	m_roomSpriteSheet = getSpriteSheetFromFilename(m_textureMapConstants->c_spriteSheetFilename);

	loadTexturesFromTileList(m_textureMapConstants->c_spriteSheetListFilename);
	loadTexturesFromTileList(m_textureMapConstants->c_weaponAnimSpriteSheetListFilename);
}

TextureMap::~TextureMap()
{
	delete m_textureMap;
	delete m_spriteSheetVecTupleTextureMap;
	delete m_spriteSheetAnimTextureMap;
	delete m_spriteSheetMap;
}

// NOTE: This function only reads from text files
void TextureMap::loadTexturesFromTileList(std::string const& spriteSheetListFilename)
{
	std::ifstream spriteSheetListFile;
	spriteSheetListFile.open(spriteSheetListFilename);

	std::string line;
	while (std::getline(spriteSheetListFile, line))
	{
		std::istringstream lineStream(line);
		std::vector<std::string> splitLine((std::istream_iterator<std::string>(lineStream)), std::istream_iterator<std::string>());

		std::string textureName;
		int topLeftX, topLeftY, width, height, frames;

		if (splitLine[0] != "#" && splitLine.size() == 5)
		{
			// Not an animation (there is no frames column)
			textureName = splitLine[0];
			topLeftX = std::stoi(splitLine[1]);
			topLeftY = std::stoi(splitLine[2]);
			width = std::stoi(splitLine[3]);
			height = std::stoi(splitLine[4]);
			std::tuple<int, int, int, int> intTuple(topLeftX, topLeftY, width, height);
			m_spriteSheetNonAnimTextureMap->insert(std::pair<std::string, std::tuple<int, int, int, int>>(textureName, intTuple));

			// Maybe just make m_spriteSheetTextureMap store tuples of ints instead of vector2fs?
			// Done: Why not just have both? Still O(N) space
			sf::Vector2f topLeftVec((float) topLeftX, (float) topLeftY); 
			sf::Vector2f topRightVec((float) (topLeftX + width), (float) topLeftY);
			sf::Vector2f bottomRightVec((float) (topLeftX + width), (float) (topLeftY + height));
			sf::Vector2f bottomLeftVec((float) topLeftX, (float) (topLeftY + height));
			std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f> vecTuple(topLeftVec, topRightVec, bottomRightVec, bottomLeftVec);
			m_spriteSheetVecTupleTextureMap->insert(std::pair<std::string, std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f>>(textureName, vecTuple));

		}
		else if (splitLine[0] != "#" && splitLine.size() == 6)
		{
			// Animation (frames column exists)
			textureName = splitLine[0];
			topLeftX = std::stoi(splitLine[1]);
			topLeftY = std::stoi(splitLine[2]);
			width = std::stoi(splitLine[3]);
			height = std::stoi(splitLine[4]);
			frames = std::stoi(splitLine[5]);

			std::tuple<int, int, int, int, int> animTuple(topLeftX, topLeftY, width, height, frames);
			m_spriteSheetAnimTextureMap->insert(std::pair<std::string, std::tuple<int, int, int, int, int>>(textureName, animTuple));
		}
	}

	spriteSheetListFile.close();
}

void TextureMap::addSpriteSheet(std::string const& spriteSheetFilename)
{
	auto it = m_spriteSheetMap->find(spriteSheetFilename);
	if (it != m_spriteSheetMap->end())
	{
		return;
	}
	else
	{
		sf::Texture *spriteSheet = new sf::Texture();
		spriteSheet->loadFromFile(spriteSheetFilename);
		m_spriteSheetMap->insert(std::pair <std::string, sf::Texture>(spriteSheetFilename, *spriteSheet));
	}
}

// Gets a texture from a filename
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
std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f>& TextureMap::getSpriteSheetVecTuple(std::string const& textureName)
{
	auto it = m_spriteSheetVecTupleTextureMap->find(textureName);
	if (it != m_spriteSheetVecTupleTextureMap->end())
	{
		return it->second;
	}

	// If textureName doesn't exist in the map, return a new dummy tuple (all values are -1, -1)
	sf::Vector2f dummy(-1, -1);
	std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f> *dummyTuple;
	dummyTuple = new std::tuple<sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f>(dummy, dummy, dummy, dummy);
	return *dummyTuple;
}

std::tuple<int, int, int, int, int>& TextureMap::getFilenameAnimVecTuple(std::string const& animFileName)
{
	return *(new std::tuple<int, int, int, int, int>(1, 1, 1, 1, 1));
}

std::tuple<int, int, int, int, int>& TextureMap::getSpriteSheetAnimVecTuple(std::string const& animName)
{
	auto it = m_spriteSheetAnimTextureMap->find(animName);
	if (it != m_spriteSheetAnimTextureMap->end())
	{
		return it->second;
	}

	// If animName doesn't exist in the map, return a new dummy tuple (all values are -1)
	return *(new std::tuple<int, int, int, int, int>(-1, -1, -1, -1, -1));
}

sf::Texture& TextureMap::getSpriteSheetFromFilename(std::string const& spriteSheetFilename)
{
	auto it = m_spriteSheetMap->find(spriteSheetFilename);
	if (it == m_spriteSheetMap->end())
	{
		addSpriteSheet(spriteSheetFilename);
	}
	return m_spriteSheetMap->at(spriteSheetFilename);
}

TextureMapConstants *TextureMap::getTextureMapConstants()
{
	return m_textureMapConstants;
}

sf::Texture& TextureMap::getRoomSpriteSheet()
{
	return m_roomSpriteSheet;
}