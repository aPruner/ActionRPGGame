#pragma once
#include "Gui.h"
#include "Player.h"

class PlayerSummaryGui : virtual public Gui {
private:
	Player *m_player;

	// TODO: Figure out what else goes here

public:
	PlayerSummaryGui(Player player);
	~PlayerSummaryGui();

	// Override for Gui::update
	void update() const override;

	// Override for Gui::update
	void draw() const override;

	// Add attribute widgets to the gui
	void addPlayerAttributeWidgets();
};
