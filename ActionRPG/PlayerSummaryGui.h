#pragma once
#include "Gui.h"
#include "Player.h"
#include "WindowGuiWidget.h"
#include "DisplayGuiWidget.h"
#include "TextGuiWidget.h"

class PlayerSummaryGui : virtual public Gui {
private:
	Player *m_player;

	WindowGuiWidget *m_windowWidget;
	DisplayGuiWidget *m_rootDisplayWidget;
	TextGuiWidget *m_strengthTextWidget;
	TextGuiWidget* m_wisdomTextWidget;
	TextGuiWidget* m_conditioningTextWidget;
	TextGuiWidget* m_agilityTextWidget;

	// TODO: Figure out what else goes here

public:
	PlayerSummaryGui(Player player);
	~PlayerSummaryGui();

	// Override for Gui::update
	void update() const override;

	// Override for Gui::update
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Add attribute widgets to the gui
	void addPlayerAttributeWidgets();
};
