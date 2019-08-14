#include <assert.h>
#include "TextureMap.h"

// Initially, the singleton instance will be null
TextureMap *TextureMap::instance = nullptr;

TextureMap::TextureMap()
{
	assert(instance == nullptr);
	instance = this;
}

sf::Texture& TextureMap::getTexture(std::string const& filename)
{
	auto& m = instance->textures;
	auto it = m.find(filename);
	if (it != m.end())
	{
		return it->second;
	}
	else
	{
		auto& texture = m[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}

// TODO: Maybe add a batch loadAllTextures method to load all textures at once in the future