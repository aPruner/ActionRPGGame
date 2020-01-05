#include "PlayerSummaryGui.h"
#include <sstream>

PlayerSummaryGui::PlayerSummaryGui(Player *player)
{
	m_player = player;
	m_height = 800;
	m_width = 800;

	// TODO: Create constants for PlayerSummaryGui, place them in PlayerConstants.h (or maybe create a new class)
	// TODO: Tune all these values so that they make sense
	// TODO: After tuning, base these values on screen resolution
	sf::Vector2f rootPosition = sf::Vector2f(350, 150);
	float rootHeight = 600;
	float rootWidth = 400;
	m_rootWindowWidget = new WindowGuiWidget(rootPosition, rootHeight, rootWidth);
	m_rootWidget = m_rootWindowWidget;

	sf::Vector2f firstChildPosition = sf::Vector2f(10, 10);
	float firstChildHeight = 580;
	float firstChildWidth = 580;
	m_firstChildDisplayWidget = new DisplayGuiWidget(firstChildPosition, rootPosition, firstChildHeight, firstChildWidth);

	// Get the font filename for the attribute text widgets
	PlayerConstants *playerConstants = m_player->getPlayerConstants();
	const std::string playerSummaryGuiFontFileName = playerConstants->c_playerSummaryGuiFontFileName;

	// Create a stringstream for text widget initialization
	std::stringstream attributeSS;

	sf::Vector2f strengthPosition = sf::Vector2f(3, 20);
	attributeSS << playerConstants->c_strengthLabel << std::to_string(player->getStrength());
	m_strengthTextWidget = new TextGuiWidget(strengthPosition, firstChildPosition, attributeSS.str(), playerSummaryGuiFontFileName);
	// Clear the stringstream
	attributeSS.str(std::string());

	sf::Vector2f wisdomPosition = sf::Vector2f(3, 40);
	attributeSS << playerConstants->c_wisdomLabel << std::to_string(player->getWisdom());
	m_wisdomTextWidget = new TextGuiWidget(wisdomPosition, firstChildPosition, attributeSS.str(), playerSummaryGuiFontFileName);
	attributeSS.str(std::string());

	sf::Vector2f conditioningPosition = sf::Vector2f(3, 60);
	attributeSS << playerConstants->c_conditioningLabel << std::to_string(player->getConditioning());
	m_conditioningTextWidget = new TextGuiWidget(conditioningPosition, firstChildPosition, attributeSS.str(), playerSummaryGuiFontFileName);
	attributeSS.str(std::string());

	sf::Vector2f agilityPosition = sf::Vector2f(3, 80);
	attributeSS << playerConstants->c_agilityLabel << std::to_string(player->getAgility());
	m_agilityTextWidget = new TextGuiWidget(agilityPosition, firstChildPosition, attributeSS.str(), playerSummaryGuiFontFileName);

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