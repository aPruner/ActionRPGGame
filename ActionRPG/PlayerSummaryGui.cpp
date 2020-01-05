#include "PlayerSummaryGui.h"

PlayerSummaryGui::PlayerSummaryGui(Player *player)
{
	m_player = player;
	m_height = 800;
	m_width = 800;

	// TODO: Create constants for PlayerSummaryGui
	m_windowWidget = new WindowGuiWidget(sf::Vector2f(800, 800), 10, 10);

}

PlayerSummaryGui::~PlayerSummaryGui()
{

}

void PlayerSummaryGui::addPlayerAttributeWidgets()
{

}