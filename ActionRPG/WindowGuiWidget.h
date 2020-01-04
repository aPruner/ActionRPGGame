#pragma once
#include "GuiWidget.h"
#include "DisplayGuiWidget.h"
#include "TextGuiWidget.h"

// Class for moveable window gui element - will be the root widget for most guis in the game (aside from menus)
class WindowGuiWidget : virtual public GuiWidget {
private:

	// Rectangle that when clicked on, closes the window
	sf::RectangleShape m_closeButton;

	// TODO: Figure out what else goes here
public:
	WindowGuiWidget(sf::Vector2f position);
	~WindowGuiWidget();

	// TODO: make a new sub type of GuiWidget in the class hierarchy tree so that this isn't duplicate code in DisplayGuiWidget
	void addChildTextWidget(TextGuiWidget newChildTextWidget);
	void addChildDisplayWidget(DisplayGuiWidget newChildDisplayWidget);

	void update() const override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};
