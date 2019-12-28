#pragma once
#include <SFML/Graphics.hpp>

// Abstract GUI class that can be extended to create other GUIs
class Gui {
private:
	// Instance of the game window
	sf::RenderWindow *m_gameWindow;


public:
	Gui(sf::RenderWindow gameWindow);
	~Gui();

	void draw();
};