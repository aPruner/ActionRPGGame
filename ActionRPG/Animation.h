#pragma once
#include <SFML/Graphics.hpp>
#include "TextureMap.h"

class Animation
{
private:
	// Vector of animation frames
	std::vector<sf::Texture> *m_animFrames;

	// Name of the animation
	std::string m_animName;

	// Sprite to be drawn
	sf::Sprite m_sprite;

	// Clock instance
	sf::Clock *m_clock;

	// TextureMap instance
	TextureMap *m_textureMap;

	void initAnimFrames();
public:
	Animation(TextureMap *textureMap, std::string const& animName);

	void startAnimation();
	void stopAnimation();
};