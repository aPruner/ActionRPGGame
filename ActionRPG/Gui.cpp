#include "Gui.h"

Gui::Gui(sf::RenderWindow gameWindow)
{
	m_gameWindow = &gameWindow;
	m_gui = new tgui::Gui(*m_gameWindow);
}

Gui::~Gui()
{
	delete m_gui;
}

void Gui::draw()
{
	m_gui->draw();
}