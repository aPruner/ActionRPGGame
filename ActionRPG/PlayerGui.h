#pragma once
#include "Gui.h"
#include "Player.h"

class PlayerGui : virtual public Gui {
private:
	Player *m_player;
public:

	// Override for Gui::update
	void update() const override;

	// Override for Gui::update
	void draw() const override;

	// Add attribute widgets to the gui
	void addPlayerAttributeWidgets();
};
