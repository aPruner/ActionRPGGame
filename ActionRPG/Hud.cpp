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
	float playerHealth = (float)m_player->getHealth();
	float startingHealth = (float)PlayerConstants::c_startingHealth;
	m_healthBarRect.setSize(sf::Vector2f(playerHealth / startingHealth * (float)400, 60)); 

	float playerMana = (float)m_player->getMana();
	float startingMana = (float)PlayerConstants::c_startingMana;
	m_manaBarRect.setSize(sf::Vector2f(playerMana / startingMana * (float)400, 60));
	
	float playerExperience = (float)m_player->getExperience();
	float experienceForNextLevel = (float)m_player->getExperienceForNextLevel();
	float playerLevel = (float)m_player->getLevel();
	// TODO: FIX THE MATH
	m_experienceBarRect.setSize(sf::Vector2f((float)400 * (playerExperience - (playerLevel - 1) * PlayerConstants::c_startingExperienceForNextLevel) / experienceForNextLevel, 60));
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
	m_healthBarRect.setOutlineThickness(1);
	
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