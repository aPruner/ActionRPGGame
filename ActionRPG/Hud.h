#include <SFML/Graphics.hpp>
#include "Player.h"

class Hud : sf::Drawable 
{
private:
	// Instance of the player
	Player *m_player;
	
	// Rectangle drawables for status bars
	sf::RectangleShape m_healthBarRect;
	sf::RectangleShape m_manaBarRect;
	sf::RectangleShape m_experienceBarRect;

	void initStatusBarRects();

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
		return m_experienceBarRect;
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
		m_experienceBarRect = experienceBarRect;
	}

};