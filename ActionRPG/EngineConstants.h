#pragma once
#include <SFML/Graphics.hpp>

class EngineConstants {
public:
	// TODO: Figure out how to define static strings so there is no need to instantiate this class
	// also figure out how to do this with the sf types, such as Vector2f and Color
	const std::string c_defaultFontFilename = "fonts/MiddleEarth.ttf";
	const std::string c_fpsCounterInitString = "FPS: ";
	const std::string c_playerDebugTextInitString = "X: %d, Y: %d";
	const sf::Vector2f c_fpsCounterPosition = sf::Vector2f(25, 25);
	const sf::Color c_defaultFontColor = sf::Color::White;
	// TODO: Change the font size of the fpsCounter to be related to resolution
	const static int c_defaultFontSize = 30;
	const float c_playerDebugTextOffsetX = 200;
	const float c_playerDebugTextOffsetY = 50;
};
