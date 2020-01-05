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
	TextGuiWidget *m_wisdomTextWidget;
	TextGuiWidget *m_conditioningTextWidget;
	TextGuiWidget *m_agilityTextWidget;

	// TODO: Figure out what else goes here

public:
	PlayerSummaryGui(Player *player);
	~PlayerSummaryGui();

	// Add attribute widgets to the gui
	void addPlayerAttributeWidgets();
};
