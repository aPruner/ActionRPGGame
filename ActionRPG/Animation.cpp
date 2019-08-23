#include "Animation.h"

Animation::Animation(TextureMap *textureMap, std::string const& animName)
{
	m_textureMap = textureMap;
	m_animName = animName;
	initAnimFrames();
	// Create the sprite from the first frame of the animation
	m_sprite = sf::Sprite(m_textureMap->getSpriteSheet(), m_animSpriteSheetBounds);
	m_isAnimating = false;
}

void Animation::initAnimFrames()
{
	sf::Texture spriteSheet = m_textureMap->getSpriteSheet();
	std::tuple<int, int, int, int, int> animTuple = m_textureMap->getSpriteSheetAnimVecTuple(m_animName);
	m_firstFrameTopLeft = sf::Vector2f((float)std::get<0>(animTuple), (float)std::get<1>(animTuple));
	m_width = std::get<2>(animTuple);
	m_height = std::get<3>(animTuple);
	m_frames = std::get<4>(animTuple);
	m_animSpriteSheetBounds = sf::IntRect((int)m_firstFrameTopLeft.x, (int)m_firstFrameTopLeft.y, m_width, m_height);
	m_animIndex = 0;

}

void Animation::animate()
{
	if (!m_isAnimating)
	{
		return;
	}

	float dtSeconds = m_clock->getElapsedTime().asSeconds();
	if (dtSeconds > 1.0f)
	{
		updateAnimationFrame();
	}
}

void Animation::updateAnimationFrame()
{
	if (m_animIndex < m_frames)
	{
		m_animSpriteSheetBounds.left += m_width;
		m_sprite.setTextureRect(m_animSpriteSheetBounds);
		m_animIndex++;
	}
	else
	{
		m_animSpriteSheetBounds.left = (int)m_firstFrameTopLeft.x;
		m_sprite.setTextureRect(m_animSpriteSheetBounds);
		m_animIndex = 0;
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