#include "Animation.h"

Animation::Animation(TextureMap* textureMap, std::string const& animName, int scalingFactor, std::string const& spriteSheetFilename, float animationSpeed, bool *isInvertedX)
{
	m_textureMap = textureMap;
	m_animName = animName;
	m_clock = new sf::Clock();
	m_animationSpeed = animationSpeed;
	initAnimFrames();
	// Create the sprite from the first frame of the animation
	m_sprite = new sf::Sprite(m_textureMap->getSpriteSheetFromFilename(spriteSheetFilename), m_animSpriteSheetBounds);
	m_scalingFactor = scalingFactor;
	m_sprite->scale((float)scalingFactor, (float)scalingFactor);
	m_isAnimating = false;
	m_isInvertedX = isInvertedX;
}

void Animation::initAnimFrames()
{
	std::tuple<int, int, int, int, int> animTuple = m_textureMap->getSpriteSheetAnimVecTuple(m_animName);
	m_firstFrameTopLeft = sf::Vector2f((float)std::get<0>(animTuple), (float)std::get<1>(animTuple));
	m_width = std::get<AnimationConstants::c_vecTupleWidthIndex>(animTuple);
	m_height = std::get<AnimationConstants::c_vecTupleHeightIndex>(animTuple);
	m_frames = std::get<AnimationConstants::c_vecTupleFramesIndex>(animTuple) - AnimationConstants::c_vecTupleFramesOffsetValue;
	m_animSpriteSheetBounds = sf::IntRect((int)m_firstFrameTopLeft.x, (int)m_firstFrameTopLeft.y, m_width, m_height);
	m_animIndex = AnimationConstants::c_animationStartIndex;
}

void Animation::resetAnimation()
{
	m_animSpriteSheetBounds.left = (int)m_firstFrameTopLeft.x;
	m_sprite->setTextureRect(m_animSpriteSheetBounds);
	m_animIndex = AnimationConstants::c_animationStartIndex;
}

void Animation::updateAnimationFrame()
{
	// If necessary, invert the sprite on this frame
	if (*m_isInvertedX)
	{
		m_sprite->setScale(AnimationConstants::c_invertedXScaleValue * m_scalingFactor, m_scalingFactor);
	}
	else
	{
		m_sprite->setScale(m_scalingFactor, m_scalingFactor);
	}

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

// Essentially acts as a setter for m_isAnimating
void Animation::startAnimation()
{
	m_isAnimating = true;
}

void Animation::stopAnimation()
{
	m_isAnimating = false;
	resetAnimation();
}

// Getters and Setters
// Getters
bool Animation::getIsAnimating()
{
	return m_isAnimating;
}

sf::Sprite *Animation::getFrameSprite()
{
	return m_sprite;
}

bool Animation::getIsInvertedX()
{
	return *m_isInvertedX;
}