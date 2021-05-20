#pragma once
#include <SFML/Graphics.hpp>

class EngineConstants {
public:
	// TODO: Figure out how to define static strings so there is no need to instantiate this class
	// also figure out how to do this with the sf types, such as Vector2f and Color
	const std::string c_fpsCounterInitString = "FPS: ";
	const std::string c_playerDebugTextInitString = "Player is facing left: ";
	const std::string c_playerInvertedXDebugString = "Inv X (run anim): ";
	const std::string c_playerSpriteScaleDebugString = "Sprite scale (run anim): ";
	const sf::Vector2f c_fpsCounterPosition = sf::Vector2f(25, 25);
	// TODO: Change the font size of the fpsCounter to be related to resolution
	const float c_playerDebugTextOffsetX = 700;
	const float c_playerDebugTextOffsetY = 300;
};
