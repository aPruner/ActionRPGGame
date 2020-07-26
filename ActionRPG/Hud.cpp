#include "Hud.h"

Hud::Hud(Player* player)
{
	// Initialize constants object
	m_engineConstants = new EngineConstants();

	// Initialize the player
	m_player = player;

	initStatusBarRects();
	initStatusText();
}

Hud::~Hud() 
{
}

void Hud::update(float timeElapsed)
{
	// TODO: Centre text on bars

	// Update the Hud piece by piece
	float playerHealth = (float)m_player->getHealth();
	float startingHealth = (float)PlayerConstants::c_startingHealth;
	m_healthBarRect.setSize(sf::Vector2f(playerHealth / startingHealth * (float)400, 60)); 

	m_healthText.setString(std::to_string((int)playerHealth));

	float playerMana = (float)m_player->getMana();
	float startingMana = (float)PlayerConstants::c_startingMana;
	m_manaBarRect.setSize(sf::Vector2f(playerMana / startingMana * (float)400, 60));

	m_manaText.setString(std::to_string((int)playerMana));
	
	// TODO: Tidy up exp towards level and exp needed for level-up
	int playerLevel = m_player->getLevel();
	float offsetTotalExperience = (float)m_player->getTotalExperience() - (playerLevel - 1) * 100;
	float offsetExperienceNeededForNextLevel = (float)m_player->getExperienceNeededForNextLevel() - (playerLevel - 1) * 100;	
	m_totalExperienceBarRect.setSize(sf::Vector2f((float)400 * offsetTotalExperience / offsetExperienceNeededForNextLevel, 60));
		
	m_totalExperienceText.setString(std::to_string((int)m_player->getTotalExperience()) + "/" + std::to_string((int)m_player->getExperienceNeededForNextLevel()));

	m_levelText.setString("Level: " + std::to_string(playerLevel));

}

// Override for sf::Drawable::draw
void Hud::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_healthBarRect, states);
	target.draw(m_manaBarRect, states);
	target.draw(m_totalExperienceBarRect, states);
	
	target.draw(m_healthText, states);
	target.draw(m_manaText, states);
	target.draw(m_totalExperienceText, states);
	target.draw(m_levelText, states);
}

void Hud::initStatusBarRects()
{
	// Init health rect
	m_healthBarRect = sf::RectangleShape(sf::Vector2f(400, 60));
	m_healthBarRect.setPosition(sf::Vector2f(100, 100));
	m_healthBarRect.setFillColor(sf::Color::Red);
	m_healthBarRect.setOutlineColor(sf::Color::White);
	m_healthBarRect.setOutlineThickness(1);
	
	// Init mana rect
	m_manaBarRect = sf::RectangleShape(sf::Vector2f(400, 60));
	m_manaBarRect.setPosition(sf::Vector2f(100, 200));
	m_manaBarRect.setFillColor(sf::Color::Blue);
	m_manaBarRect.setOutlineColor(sf::Color::White);
	m_manaBarRect.setOutlineThickness((float)1);

	// Init experience rect
	m_totalExperienceBarRect = sf::RectangleShape(sf::Vector2f(400, 60));
	m_totalExperienceBarRect.setPosition(sf::Vector2f(100, 300));
	m_totalExperienceBarRect.setFillColor(sf::Color::Green);
	m_totalExperienceBarRect.setOutlineColor(sf::Color::White);
	m_totalExperienceBarRect.setOutlineThickness((float)1);
}

void Hud::initStatusText()
{	
	m_statusBarFont.loadFromFile(m_engineConstants->c_defaultFontFilename);

	m_healthText.setFont(m_statusBarFont);
	m_healthText.setCharacterSize(m_engineConstants->c_defaultFontSize);
	m_healthText.setFillColor(m_engineConstants->c_defaultFontColor);
	m_healthText.setPosition(sf::Vector2f(280, 110));

	m_manaText.setFont(m_statusBarFont);
	m_manaText.setCharacterSize(m_engineConstants->c_defaultFontSize);
	m_manaText.setFillColor(m_engineConstants->c_defaultFontColor);
	m_manaText.setPosition(sf::Vector2f(280, 210));

	m_totalExperienceText.setFont(m_statusBarFont);
	m_totalExperienceText.setCharacterSize(m_engineConstants->c_defaultFontSize);
	m_totalExperienceText.setFillColor(m_engineConstants->c_defaultFontColor);
	m_totalExperienceText.setPosition(sf::Vector2f(250, 310));

	m_levelText.setString("Level: ");
	m_levelText.setFont(m_statusBarFont);
	m_levelText.setCharacterSize(m_engineConstants->c_defaultFontSize);
	m_levelText.setFillColor(m_engineConstants->c_defaultFontColor);
	m_levelText.setPosition(sf::Vector2f(100, 410));

}