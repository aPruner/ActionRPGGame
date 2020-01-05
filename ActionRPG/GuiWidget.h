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

	// Vector position relative to the origin of the parent Gui/GuiWidget
	sf::Vector2f m_position;

	// Child widgets rendered inside of this widget
	std::vector<GuiWidget *>* m_childWidgets;

	// Rectangle drawables for debugging 
	sf::RectangleShape m_debugRectOutline; // (outline of GuiWidget)
	sf::RectangleShape m_debugRectOrigin; // (origin of GuiWidget)

	// TODO: Figure out what else goes here

public:

	// Pure virtual method for updating the gui widget
	// Must be defined in the derived class
	virtual void update() const = 0;

	// Pure virtual method for drawing the gui widget
	// Must be defined in the derived class
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	// Getters and Setters

	// Getters
	bool getIsVisible();

	// Setters
	void setIsVisible(bool isVisible);
};