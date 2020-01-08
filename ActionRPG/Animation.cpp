#include "Animation.h"

Animation::Animation(TextureMap *textureMap, std::string const& animName, std::string const& spriteSheetFilename)
{
	m_textureMap = textureMap;
	m_animName = animName;
	m_clock = new sf::Clock();
	initAnimFrames();
	// Create the sprite from the first frame of the animation
	m_sprite = new sf::Sprite(m_textureMap->getSpriteSheetFromFilename(spriteSheetFilename), m_animSpriteSheetBounds);
	m_sprite->scale((float)AnimationConstants::c_defaultScalingFactor, (float)AnimationConstants::c_defaultScalingFactor);
	m_isAnimating = false;
}

Animation::Animation(TextureMap* textureMap, std::string const& animName, int scalingFactor, std::string const& spriteSheetFilename)
{
	m_textureMap = textureMap;
	m_animName = animName;
	m_clock = new sf::Clock();
	initAnimFrames();
	// Create the sprite from the first frame of the animation
	m_sprite = new sf::Sprite(m_textureMap->getSpriteSheetFromFilename(spriteSheetFilename), m_animSpriteSheetBounds);
	m_sprite->scale((float)scalingFactor, (float)scalingFactor);
	m_isAnimating = false;
}

void Animation::initAnimFrames()
{
	std::tuple<int, int, int, int, int> animTuple = m_textureMap->getSpriteSheetAnimVecTuple(m_animName);
	m_firstFrameTopLeft = sf::Vector2f((float)std::get<0>(animTuple), (float)std::get<1>(animTuple));
	m_width = std::get<2>(animTuple);
	m_height = std::get<3>(animTuple);
	m_frames = std::get<4>(animTuple) - 1;
	m_animSpriteSheetBounds = sf::IntRect((int)m_firstFrameTopLeft.x, (int)m_firstFrameTopLeft.y, m_width, m_height);
	m_animIndex = 0;
}

void Animation::updateAnimationFrame()
{
	if (m_animIndex < m_frames)
	{
		m_animSpriteSheetBounds.left += m_width;
		m_sprite->setTextureRect(m_animSpriteSheetBounds);
		m_animIndex++;
	}
	else
	{
		m_animSpriteSheetBounds.left = (int)m_firstFrameTopLeft.x;
		m_sprite->setTextureRect(m_animSpriteSheetBounds);
		m_animIndex = 0;
	}
}

// Assumes that the isAnimating() currently returns true
void Animation::animate()
{
	float dtSeconds = m_clock->getElapsedTime().asSeconds();
	// TODO: this 0.1f should be a constant
	if (dtSeconds > 0.1f)
	{
		updateAnimationFrame();
		m_clock->restart();
	}
}

void Animation::startAnimation()
{
	m_isAnimating = true;
}

void Animation::stopAnimation()
{
	m_isAnimating = false;
}

bool Animation::isAnimating()
{
	return m_isAnimating;
}

sf::Sprite *Animation::getFrameSprite()
{
	return m_sprite;
}