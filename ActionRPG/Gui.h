#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

// Abstract GUI class that can be extended to create other GUIs with TGUI
class Gui {
private:
	// Instance of the game window
	sf::RenderWindow *m_gameWindow;

	// Tgui gui instance
	tgui::Gui *m_gui;

public:
	Gui(sf::RenderWindow gameWindow);
	~Gui();

	void draw();
};