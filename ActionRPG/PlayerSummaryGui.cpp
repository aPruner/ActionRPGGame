#include "PlayerSummaryGui.h"

PlayerSummaryGui::PlayerSummaryGui(Player player)
{
	m_player = &player;
	m_height = 500;
	m_width = 500;
}

PlayerSummaryGui::~PlayerSummaryGui()
{

}

void PlayerSummaryGui::addPlayerAttributeWidgets()
{

}

// Override for Gui::draw
void PlayerSummaryGui::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// TODO: figure out what to draw
	// target.draw(m_sprite, states);
}

// Override for Gui::update
void PlayerSummaryGui::update() const
{

}