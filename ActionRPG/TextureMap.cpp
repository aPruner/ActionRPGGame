#include <assert.h>
#include "TextureMap.h"

TextureMap::TextureMap()
{
	textureMap = new std::map<std::string, sf::Texture>();
}

TextureMap::~TextureMap()
{
	delete textureMap;
}

sf::Texture& TextureMap::getTexture(std::string const& filename)
{
	auto it = textureMap->find(filename);
	if (it != textureMap->end())
	{
		return it->second;
	}
	else
	{
		sf::Texture texture;
		texture.loadFromFile(filename);
		textureMap->insert(std::pair<std::string, sf::Texture>(filename, texture));
		return textureMap->at(filename);
	}
}

// TODO: Maybe add a batch loadAllTextures method to load all textures at once in the future