#pragma once
#include "GuiWidget.h"

// Class for moveable window gui element - will be the root widget for most guis in the game (aside from menus)
class WindowGuiWidget : virtual public GuiWidget {
private:

	bool m_isMovable;

	// TODO: Figure out what else goes here
public:

	void update() const override;
	void draw() const override;

};
