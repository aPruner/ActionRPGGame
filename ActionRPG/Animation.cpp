#include "Animation.h"

Animation::Animation(TextureMap *textureMap, std::string const& animName)
{
	m_textureMap = textureMap;
	m_animName = animName;
	m_animFrames = new std::vector<sf::Texture>();
	initAnimFrames();
	// Create the sprite from the first frame of the animation
	m_sprite = sf::Sprite(m_animFrames->at(0));
}

void Animation::initAnimFrames()
{
	sf::Texture spriteSheet = m_textureMap->getSpriteSheet();
	std::tuple<int, int, int, int, int> animTuple = m_textureMap->getSpriteSheetAnimVecTuple(m_animName);
	int topLeftX, topLeftY, width, height, frames;
	topLeftX = std::get<0>(animTuple);
	topLeftY = std::get<1>(animTuple);
	width = std::get<2>(animTuple);
	height = std::get<3>(animTuple);
	frames = std::get<4>(animTuple);
	for (int i = 0; i < frames; i++)
	{
		sf::IntRect spriteSheetBounds(topLeftX + i * width, topLeftY, width, height);
		sf::Sprite tmpSprite(spriteSheet, spriteSheetBounds);
		m_animFrames->push_back(*tmpSprite.getTexture());
	}
}

void Animation::startAnimation()
{

}

void Animation::stopAnimation()
{

}