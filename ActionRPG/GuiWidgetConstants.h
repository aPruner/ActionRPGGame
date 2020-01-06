#pragma once
#include <SFML/Graphics.hpp>

class GuiWidgetConstants {
public:
	// DisplayWidget Constants
	const sf::Color c_defaultDisplayWidgetDebugRectColor = sf::Color::Cyan;

	// TextGuiWidget Constants
	const sf::Color c_defaultTextWidgetFillColor = sf::Color::White;
	const static int c_defaultTextWidgetFontSize = 30;

	// WindowGuiWidget Constants
	const sf::Vector2f c_defaultWindowWidgetParentPosition = sf::Vector2f(0, 0);
	const sf::Color c_defaultWindowWidgetDebugRectColor = sf::Color::Yellow;
};