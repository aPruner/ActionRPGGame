#include "TextureMap.h"

TextureMap::TextureMap()
{
	textureMap = new std::map<std::string, sf::Texture>();
	instance = this;
}

sf::Texture& TextureMap::getTexture(std::string const& filename)
{
	auto &textureMap = instance->textureMap;
	if (textureMap->find(filename) != textureMap->end())
	{
		return textureMap->at(filename);
	}
	else
	{
		sf::Texture texture;
		texture.loadFromFile(filename);
		textureMap->insert(std::pair<std::string, sf::Texture>(filename, texture));
		return texture;
	}
}

// TODO: Maybe add a batch loadAllTextures method to load all textures at once in the future