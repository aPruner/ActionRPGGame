#pragma once
#include <SFML/Graphics.hpp>
#include "TextureMap.h"

class Animation
{
private:
	// Vector of animation frames
	std::vector<sf::Texture *> m_animFrames;

	// Sprite to be drawn
	sf::Sprite m_sprite;

	// Clock instance
	sf::Clock *m_clock;

	// TextureMap instance
	TextureMap *m_textureMap;
public:
	Animation(TextureMap *textureMap);

	void startAnimation();
	void stopAnimation();
};