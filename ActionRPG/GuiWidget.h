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

	// Vector position relative to the origin of the parent GuiWidget
	sf::Vector2f m_position;

	// Vector position of the parent GuiWidget
	// If this widget is a root, this will be set to 0, 0
	sf::Vector2f m_parentPosition;

	// Child widgets rendered inside of this widget
	std::vector<GuiWidget *> *m_childWidgets;

	// Flag for whether or not to draw debug rectangles
	bool m_drawDebugRects;

	// Rectangle drawables for debugging 
	sf::RectangleShape m_debugRectOutline; // (outline of GuiWidget)
	sf::RectangleShape m_debugRectOrigin; // (origin of GuiWidget)

public:

	// Pure virtual method for updating the gui widget
	// Must be defined in the derived class
	virtual void update() const = 0;

	// Pure virtual method for drawing the gui widget
	// Must be defined in the derived class
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	// Recursively sets isVisible to true for all child widgets
	void setIsVisible(bool isVisible);

	// Getters and Setters
	// Getters
	bool getIsVisible();
	bool getDebugStatus();

};