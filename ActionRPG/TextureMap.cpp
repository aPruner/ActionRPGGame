#include "TextureMap.h"

TextureMap::TextureMap()
{
	textureMap = new std::map<std::string, sf::Texture>();
	instance = this;
}

sf::Texture& TextureMap::getTexture(std::string const& filename)
{
	
}

void TextureMap::addTexture(std::string const& filename)
{

}