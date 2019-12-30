#pragma once
#include "GuiWidget.h"

// Class for moveable window gui element - will be the root widget for most guis in the game (aside from menus)
class WindowGuiWidget : virtual public GuiWidget {
private:

	// Rectangle that when clicked on, closes the window
	sf::RectangleShape m_closeBounds;

	// TODO: Figure out what else goes here
public:

	void update() const override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};
