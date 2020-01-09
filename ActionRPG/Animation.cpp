#include "Animation.h"

// Only difference between these two constructors is the scaling factor
Animation::Animation(TextureMap *textureMap, std::string const& animName, std::string const& spriteSheetFilename, float animationSpeed)
{
	initAnimation(textureMap, animName, spriteSheetFilename, animationSpeed);
	m_sprite->scale((float)AnimationConstants::c_defaultScalingFactor, (float)AnimationConstants::c_defaultScalingFactor);
}

Animation::Animation(TextureMap *textureMap, std::string const& animName, int scalingFactor, std::string const& spriteSheetFilename, float animationSpeed)
{
	initAnimation(textureMap, animName, spriteSheetFilename, animationSpeed);
	m_sprite->scale((float)scalingFactor, (float)scalingFactor);
}

void Animation::initAnimation(TextureMap* textureMap, std::string const& animName, std::string const& spriteSheetFilename, float animationSpeed)
{
	m_textureMap = textureMap;
	m_animName = animName;
	m_clock = new sf::Clock();
	m_animationSpeed = animationSpeed;
	initAnimFrames();
	// Create the sprite from the first frame of the animation
	m_sprite = new sf::Sprite(m_textureMap->getSpriteSheetFromFilename(spriteSheetFilename), m_animSpriteSheetBounds);
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

void Animation::resetAnimation()
{
	m_animSpriteSheetBounds.left = (int)m_firstFrameTopLeft.x;
	m_sprite->setTextureRect(m_animSpriteSheetBounds);
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
		resetAnimation();
	}
}

// Assumes that the isAnimating() currently returns true
void Animation::animate()
{
	float dtSeconds = m_clock->getElapsedTime().asSeconds();
	if (dtSeconds > m_animationSpeed)
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
	resetAnimation();
}

bool Animation::isAnimating()
{
	return m_isAnimating;
}

sf::Sprite *Animation::getFrameSprite()
{
	return m_sprite;
}