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

	sf::Vector2f firstChildRelativePosition = sf::Vector2f(10, 10);
	float firstChildHeight = 580;
	float firstChildWidth = 380;
	m_firstChildDisplayWidget = new DisplayGuiWidget(firstChildRelativePosition, rootPosition, firstChildHeight, firstChildWidth);
	sf::Vector2f firstChildAbsolutePosition = sf::Vector2f(rootPosition.x + firstChildRelativePosition.x, rootPosition.y + firstChildRelativePosition.y);

	// Get the font filename for the attribute text widgets
	PlayerConstants *playerConstants = m_player->getPlayerConstants();
	const std::string playerSummaryGuiFontFileName = playerConstants->c_playerSummaryGuiFontFileName;

	// Create a stringstream for text widget initialization
	std::stringstream attributeSS;

	sf::Vector2f strengthPosition = sf::Vector2f(5, 5);
	attributeSS << playerConstants->c_strengthLabel << std::to_string(player->getStrength());
	m_strengthTextWidget = new TextGuiWidget(strengthPosition, firstChildAbsolutePosition, attributeSS.str(), playerSummaryGuiFontFileName);
	// Clear the stringstream
	attributeSS.str(std::string());

	sf::Vector2f wisdomPosition = sf::Vector2f(5, 30);
	attributeSS << playerConstants->c_wisdomLabel << std::to_string(player->getWisdom());
	m_wisdomTextWidget = new TextGuiWidget(wisdomPosition, firstChildAbsolutePosition, attributeSS.str(), playerSummaryGuiFontFileName);
	attributeSS.str(std::string());

	sf::Vector2f conditioningPosition = sf::Vector2f(5, 55);
	attributeSS << playerConstants->c_conditioningLabel << std::to_string(player->getConditioning());
	m_conditioningTextWidget = new TextGuiWidget(conditioningPosition, firstChildAbsolutePosition, attributeSS.str(), playerSummaryGuiFontFileName);
	attributeSS.str(std::string());

	sf::Vector2f agilityPosition = sf::Vector2f(5, 80);
	attributeSS << playerConstants->c_agilityLabel << std::to_string(player->getAgility());
	m_agilityTextWidget = new TextGuiWidget(agilityPosition, firstChildAbsolutePosition, attributeSS.str(), playerSummaryGuiFontFileName);

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