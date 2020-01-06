#include "PlayerSummaryGui.h"
#include <sstream>

PlayerSummaryGui::PlayerSummaryGui(Player *player)
{
	m_player = player;
	m_height = 800;
	m_width = 800;

	// TODO: Base these values on screen resolution
	PlayerConstants* playerConstants = m_player->getPlayerConstants();
	m_rootWindowWidget = new WindowGuiWidget(
		playerConstants->c_rootPosition,
		playerConstants->c_rootHeight,
		playerConstants->c_rootWidth
	);
	m_rootWidget = m_rootWindowWidget;

	m_firstChildDisplayWidget = new DisplayGuiWidget(
		playerConstants->c_firstChildRelativePosition,
		playerConstants->c_rootPosition,
		playerConstants->c_firstChildHeight,
		playerConstants->c_firstChildWidth
	);

	// Create a stringstream for text widget initialization
	std::stringstream attributeSS;

	attributeSS << playerConstants->c_strengthLabel << std::to_string(player->getStrength());
	m_strengthTextWidget = new TextGuiWidget(
		playerConstants->c_strengthPosition,
		playerConstants->c_firstChildAbsolutePosition,
		attributeSS.str(),
		playerConstants->c_playerSummaryGuiFontFileName);
	// Clear the stringstream after using it for each string value
	attributeSS.str(std::string());

	attributeSS << playerConstants->c_wisdomLabel << std::to_string(player->getWisdom());
	m_wisdomTextWidget = new TextGuiWidget(
		playerConstants->c_wisdomPosition,
		playerConstants->c_firstChildAbsolutePosition,
		attributeSS.str(),
		playerConstants->c_playerSummaryGuiFontFileName);
	attributeSS.str(std::string());

	attributeSS << playerConstants->c_conditioningLabel << std::to_string(player->getConditioning());
	m_conditioningTextWidget = new TextGuiWidget(
		playerConstants->c_conditioningPosition,
		playerConstants->c_firstChildAbsolutePosition,
		attributeSS.str(),
		playerConstants->c_playerSummaryGuiFontFileName);
	attributeSS.str(std::string());

	attributeSS << playerConstants->c_agilityLabel << std::to_string(player->getAgility());
	m_agilityTextWidget = new TextGuiWidget(
		playerConstants->c_agilityPosition,
		playerConstants->c_firstChildAbsolutePosition,
		attributeSS.str(),
		playerConstants->c_playerSummaryGuiFontFileName);

	buildWidgetTree();
}

PlayerSummaryGui::~PlayerSummaryGui()
{
}

void PlayerSummaryGui::buildWidgetTree()
{
	m_firstChildDisplayWidget->addChildTextWidget(m_strengthTextWidget);
	m_firstChildDisplayWidget->addChildTextWidget(m_wisdomTextWidget);
	m_firstChildDisplayWidget->addChildTextWidget(m_conditioningTextWidget);
	m_firstChildDisplayWidget->addChildTextWidget(m_agilityTextWidget);
	m_rootWindowWidget->addChildDisplayWidget(m_firstChildDisplayWidget);
}