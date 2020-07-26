#include <SFML/Graphics.hpp>
#include "EngineConstants.h"
#include "Player.h"

class Hud : public sf::Drawable 
{
private:
	// Engine constants
	EngineConstants* m_engineConstants;
	
	// Instance of the player
	Player *m_player;

	// Rectangle drawables for status bars
	sf::RectangleShape m_healthBarRect;
	sf::RectangleShape m_manaBarRect;
	sf::RectangleShape m_totalExperienceBarRect;

	// Font for status bar text
	sf::Font m_statusBarFont;

	// Text for status bars
	sf::Text m_healthText;
	sf::Text m_manaText;
	sf::Text m_totalExperienceText;

	// Text for level
	sf::Text m_levelText;

	void initStatusBarRects();
	void initStatusText();

public:
	Hud(Player* player);
	~Hud();

	// Method for updating the Hud
	void update(float timeElapsed);

	// Override for sf::Drawable::draw
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Getters and Setters
	// Getters
	sf::RectangleShape getHealthBarRect()
	{
		return m_healthBarRect;
	}

	sf::RectangleShape getManaBarRect()
	{
		return m_manaBarRect;
	}

	sf::RectangleShape getExperienceBarRect()
	{
		return m_totalExperienceBarRect;
	}

	sf::Text getHealthText()
	{
		return m_healthText;
	}

	// Setters
	void setHealthBarRect(sf::RectangleShape healthBarRect)
	{
		m_healthBarRect = healthBarRect;
	}

	void setManaBarRect(sf::RectangleShape manaBarRect)
	{
		m_manaBarRect = manaBarRect;
	}

	void setExperienceBarRect(sf::RectangleShape experienceBarRect)
	{
		m_totalExperienceBarRect = experienceBarRect;
	}

	void setHealthText(sf::Text healthText)
	{
		m_healthText = healthText;
	}

};