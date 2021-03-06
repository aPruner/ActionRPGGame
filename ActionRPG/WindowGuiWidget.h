#pragma once
#include "GuiWidget.h"
#include "DisplayGuiWidget.h"
#include "TextGuiWidget.h"

// Class for window gui element - will be the root widget for most guis in the game (aside from menus)
class WindowGuiWidget : virtual public GuiWidget {
private:
	// GuiWidgetConstants object
	GuiWidgetConstants* m_guiWidgetConstants;

	// NOTE: For now, a WindowGuiWidget can only be a root widget

	// TODO: Make this a DisplayGuiWidget instead to display some cool texture in the background
	// Background of the Window
	sf::RectangleShape m_backgroundRect;

	// Rectangle that when clicked on, closes the window
	sf::RectangleShape m_closeButtonRect;

public:
	WindowGuiWidget(sf::Vector2f position, float height, float width);
	~WindowGuiWidget();

	// TODO: make a new sub type of GuiWidget in the class hierarchy tree so that this isn't duplicate code in DisplayGuiWidget
	void addChildTextWidget(TextGuiWidget *newChildTextWidget);
	void addChildDisplayWidget(DisplayGuiWidget *newChildDisplayWidget);

	void update() const override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};
