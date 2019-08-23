#pragma once
#include <SFML/Graphics.hpp>
#include "TextureMap.h"

class Animation
{
private:
	// TODO: reduce duplicate code
	const static int c_animScalingFactor = 2;

	// Represents the current frame of the animation in the sprite sheet
	sf::IntRect m_animSpriteSheetBounds;

	// Number of frames in the animation
	int m_frames;

	// Width of each frame
	int m_width;

	// Height of each frame
	int m_height;

	// Vector representing the topLeft point of the first frame
	sf::Vector2f m_firstFrameTopLeft;

	// Name of the animation
	std::string m_animName;

	// Sprite to be drawn on the current frame
	sf::Sprite *m_sprite;

	// Bool marking whether animation is happening
	bool m_isAnimating;

	// Current frame index
	int m_animIndex;

	// Clock instance
	sf::Clock *m_clock;

	// TextureMap instance
	TextureMap *m_textureMap;

	// Adds the animation frames to m_animFrames vector
	void initAnimFrames();

	// Update the frame
	void updateAnimationFrame();
public:
	Animation(TextureMap *textureMap, std::string const& animName);

	// Get the sprite of the current frame
	sf::Sprite *getFrameSprite();

	bool isAnimating();

	// Run the animation
	void animate();

	// Set the isAnimating flag
	void startAnimation();
	void stopAnimation();
};