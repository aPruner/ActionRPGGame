#pragma once
#include <SFML/Graphics.hpp>

// Abstract GUI class that can be extended to create other GUIs
class Gui {
protected:
	// Instance of the game window
	sf::RenderWindow *m_gameWindow;

	// FloatRect representing the guiWindow
	sf::FloatRect m_guiWindow;

	// View to be drawn to
	sf::View m_view;

	// Gui dimensions
	float m_height;
	float m_width;

	// Is the gui visible
	bool m_isVisible;

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