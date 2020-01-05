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

	// Root widget (drawing this draws its whole widget tree)
	GuiWidget *m_rootWidget;

	// Gui dimensions
	float m_height;
	float m_width;

	// Is the gui visible
	bool m_isVisible;

	// Rectangle drawables for debugging 
	sf::RectangleShape m_debugRectOutline; // (outline of Gui)
	sf::RectangleShape m_debugRectOrigin; // (origin of GameObject)

public:
	// Open the gui
	void open();
	
	// Close the gui
	void close();

	// Getters and Setters
	// Getters
	GuiWidget *getRootWidget();
	bool getIsVisible();

	// Setters
	void setRootWidget(GuiWidget *newRootWidget);
};