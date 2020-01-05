#pragma once
#include "Gui.h"
#include "Player.h"
#include "WindowGuiWidget.h"
#include "DisplayGuiWidget.h"
#include "TextGuiWidget.h"

class PlayerSummaryGui : virtual public Gui {
private:
	Player *m_player;

	WindowGuiWidget* m_rootWindowWidget;
	DisplayGuiWidget *m_firstChildDisplayWidget;
	// TODO: add more DisplayGuiWidgets, one for each attribute

	TextGuiWidget *m_strengthTextWidget;
	TextGuiWidget *m_wisdomTextWidget;
	TextGuiWidget *m_conditioningTextWidget;
	TextGuiWidget *m_agilityTextWidget;

	// Construct the widget tree
	void buildWidgetTree();

public:
	PlayerSummaryGui(Player *player);
	~PlayerSummaryGui();
};
