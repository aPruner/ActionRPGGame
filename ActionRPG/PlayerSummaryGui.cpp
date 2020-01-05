#include "PlayerSummaryGui.h"

PlayerSummaryGui::PlayerSummaryGui(Player *player)
{
	m_player = player;
	m_height = 800;
	m_width = 800;

	// TODO: Create constants for PlayerSummaryGui
	// TODO: base these values on screen resolution
	// TODO: tune all these values so that they make sense
	sf::Vector2f rootPosition = sf::Vector2f(800, 600);
	float rootHeight = 800;
	float rootWidth = 600;
	m_rootWidget = new WindowGuiWidget(rootPosition, rootHeight, rootWidth);

	sf::Vector2f firstChildPosition = sf::Vector2f(10, 10);
	float firstChildHeight = 580;
	float firstChildWidth = 580;
	m_firstChildDisplayWidget = new DisplayGuiWidget(firstChildPosition, rootPosition, firstChildHeight, firstChildWidth);

	sf::Vector2f strengthPosition = sf::Vector2f(2, 2);
	std::string strengthString = std::to_string(player->getStrength());
	m_strengthTextWidget = new TextGuiWidget(strengthPosition, firstChildPosition, strengthString);

	sf::Vector2f wisdomPosition = sf::Vector2f(2, 2);
	std::string wisdomString = std::to_string(player->getWisdom());
	m_wisdomTextWidget = new TextGuiWidget(wisdomPosition, firstChildPosition, wisdomString);

	sf::Vector2f conditioningPosition = sf::Vector2f(2, 2);
	std::string conditioningString = std::to_string(player->getConditioning());
	m_conditioningTextWidget = new TextGuiWidget(conditioningPosition, firstChildPosition, conditioningString);

	sf::Vector2f agilityPosition = sf::Vector2f(2, 2);
	std::string agilityString = std::to_string(player->getAgility());
	m_agilityTextWidget = new TextGuiWidget(agilityPosition, firstChildPosition, agilityString);
}

PlayerSummaryGui::~PlayerSummaryGui()
{

}

void PlayerSummaryGui::addPlayerAttributeWidgets()
{

}