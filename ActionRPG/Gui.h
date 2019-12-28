#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

class Gui {
private:
	// Instance of the game window
	sf::RenderWindow *m_gameWindow;

	// Tgui gui instance
	tgui::Gui *m_gui;

public:
	Gui(sf::RenderWindow gameWindow);
	~Gui();
};