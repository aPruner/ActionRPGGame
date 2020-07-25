#include "Hud.h"

Hud::Hud(Player* player)
{
	// Initialize the player
	m_player = player;

	initStatusBarRects();
}

Hud::~Hud() 
{
}

void Hud::update(float timeElapsed)
{
	// Update the Hud piece by piece
	m_healthBarRect.setSize(sf::Vector2f(m_player->getHealth() / PlayerConstants::c_startingHealth * 400, 60));
	m_manaBarRect.setSize(sf::Vector2f(m_player->getMana() / PlayerConstants::c_startingMana * 400, 60));
	
	// TODO: create getter for current experience
	//m_experienceBarRect.setSize(sf::Vector2f(100 / m_player->getExperience(), 60));
}

// Override for sf::Drawable::draw
void Hud::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_healthBarRect, states);
	target.draw(m_manaBarRect, states);
	target.draw(m_experienceBarRect, states);

}

void Hud::initStatusBarRects()
{
	// Init health rect
	m_healthBarRect = sf::RectangleShape(sf::Vector2f(400, 60));
	m_healthBarRect.setPosition(sf::Vector2f(100, 100));
	m_healthBarRect.setFillColor(sf::Color::Red);
	m_healthBarRect.setOutlineColor(sf::Color::Black);
	m_healthBarRect.setOutlineThickness((float)1);
	
	// Init mana rect
	m_manaBarRect = sf::RectangleShape(sf::Vector2f(400, 60));
	m_manaBarRect.setPosition(sf::Vector2f(100, 200));
	m_manaBarRect.setFillColor(sf::Color::Blue);
	m_manaBarRect.setOutlineColor(sf::Color::Black);
	m_manaBarRect.setOutlineThickness((float)1);

	// Init experience rect
	m_experienceBarRect = sf::RectangleShape(sf::Vector2f(400, 60));
	m_experienceBarRect.setPosition(sf::Vector2f(100, 300));
	m_experienceBarRect.setFillColor(sf::Color::Green);
	m_experienceBarRect.setOutlineColor(sf::Color::Black);
	m_experienceBarRect.setOutlineThickness((float)1);
}