#pragma once
#include <sstream>
#include "Gui.h"
#include "Player.h"
#include "WindowGuiWidget.h"
#include "DisplayGuiWidget.h"
#include "TextGuiWidget.h"

class PlayerSummaryGui : virtual public Gui {
private:
	// Instance of the player
	Player *m_player;

	// Window and Display Widgets
	WindowGuiWidget *m_rootWindowWidget;
	DisplayGuiWidget *m_firstChildDisplayWidget;
	DisplayGuiWidget *m_titleDisplayWidget;

	// Text Widgets
	TextGuiWidget *m_titleTextWidget;
	TextGuiWidget *m_nameTextWidget;
	TextGuiWidget *m_levelTextWidget;
	TextGuiWidget *m_attributesTitleTextWidget;
	TextGuiWidget *m_strengthTextWidget;
	TextGuiWidget *m_wisdomTextWidget;
	TextGuiWidget *m_conditioningTextWidget;
	TextGuiWidget *m_agilityTextWidget;

	// Construct the widget tree
	void buildWidgetTree();

public:
	PlayerSummaryGui(Player *player);
	~PlayerSummaryGui();

	// TODO: Later on, add complex functionality (things that happen when button widgets are pressed, etc)
};
