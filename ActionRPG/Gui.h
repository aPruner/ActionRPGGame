#pragma once
#include <SFML/Graphics.hpp>
#include "GuiWidget.h"

// Abstract GUI class that can be extended to create other GUIs
class Gui {
protected:
	// Name of the gui
	std::string m_guiName;

	// Instance of the game window
	sf::RenderWindow m_gameWindow;

	// FloatRect representing the guiWindow
	sf::FloatRect m_guiWindow;

	// View to be drawn to
	sf::View m_view;

	// Vector of widgets to be drawn
	std::vector<GuiWidget> *m_widgets;

	// Gui dimensions
	float m_height;
	float m_width;

	// Is the gui visible
	bool m_isVisible;

	// Rectangle drawables for debugging 
	sf::RectangleShape m_debugRectOutline; // (outline of Gui)
	sf::RectangleShape m_debugRectOrigin; // (origin of GameObject)

public:
	// Pure virtual method for updating the gui
	// Must be defined in the derived class
	virtual void update() const = 0;

	// Pure virtual method for drawing the gui
	// Must be defined in the derived class
	virtual void draw() const = 0;

	// Open the gui
	void open();
	
	// Close the gui
	void close();
};