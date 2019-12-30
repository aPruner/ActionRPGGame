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

	// Is the widget visible
	bool m_isVisible;

	// Vector position relative to the origin of the parent Gui
	sf::Vector2f m_position;

	// Rectangle drawables for debugging 
	sf::RectangleShape m_debugRectOutline; // (outline of GuiWidget)
	sf::RectangleShape m_debugRectOrigin; // (origin of GuiWidget)

	// Child widgets rendered on top of this widget, if this vector is empty, this is a leaf widget
	std::vector<GuiWidget> *m_childWidgets;

	// TODO: Figure out what else goes here

public:
	virtual void update() const = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	// Getters and Setters

	// Getters
	bool getIsVisible();

	// Setters
	void setIsVisible(bool isVisible);
};