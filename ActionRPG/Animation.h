#pragma once
#include <SFML/Graphics.hpp>
#include "TextureMap.h"
#include "AnimationConstants.h"

class Animation
{
private:
	// Represents the current frame of the animation in the sprite sheet
	sf::IntRect m_animSpriteSheetBounds;

	// Number of frames in the animation
	int m_frames;

	// Width of each frame
	int m_width;

	// Height of each frame
	int m_height;

	// Speed of the animation (update time interval)
	float m_animationSpeed;

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

	// Flags for whether or not the animation is currently inverted
	bool m_isInvertedX;
	bool m_isInvertedY;

	// Called by constructors to init member variables
	void initAnimation(TextureMap* textureMap, std::string const& animName, std::string const& spriteSheetFilename, float animationSpeed);

	// Adds the animation frames to m_animFrames vector
	void initAnimFrames();

	// Update the frame
	void updateAnimationFrame();

	// Reset the animation back to its initial state
	void resetAnimation();
public:
	// Animation constructor
	Animation(TextureMap *textureMap, std::string const& animName, int scalingFactor, std::string const& spriteSheetFilename, float animationSpeed);

	// Get the sprite of the current frame
	sf::Sprite *getFrameSprite();

	// Run the animation
	void animate();

	// Set the isAnimating flag (setters with side effects)
	void startAnimation();
	void stopAnimation();

	// Getters and Setters
	// Getters
	bool getIsAnimating();
	bool getIsInvertedX();
	bool getIsInvertedY();

	// Setters
	void setIsInvertedX(bool isInvertedX);
	void setIsInvertedY(bool isInvertedY);
};