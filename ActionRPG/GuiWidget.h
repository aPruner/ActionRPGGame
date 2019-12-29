#pragma once
#include <SFML/Graphics.hpp>

// Abstract class from which to create Gui Widgets
class GuiWidget : public sf::Drawable {
protected:
	// Name of the widget
	std::string m_widgetName;

	// Widget size
	float m_height;
	float m_width;

	// Scaling factor (by default, set this to 1)
	int m_widgetScalingFactor;

	// Vector position relative to the origin of the parent Gui
	sf::Vector2f m_position;

	// TODO: Figure out what else goes here

public:
	virtual void update() const = 0;
	virtual void draw() const = 0;
};