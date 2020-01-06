#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class PlayerConstants {
public:
	// Player Constants

	// Player Class enum
	const enum class PlayerClass { Knight, Wizard, Elf, Dino };

	// Starting level
	const static int c_startingLevel = 1;

	// Starting base health and speed
	const static int c_startingHealth = 100;
	const static int c_startingSpeed = 200;

	// Starting base attributes
	// TODO: Change these back to all 4, changed them for debugging purposes
	const static int c_startingStrength = 4;
	const static int c_startingWisdom = 5;
	const static int c_startingConditioning = 6;
	const static int c_startingAgility = 7;
	
	std::string c_idleAnimName;
	std::string c_runAnimName;
	std::string c_hitAnimName;

	const std::string& getPlayerIdleAnimName(PlayerClass playerClass);
	const std::string& getPlayerRunAnimName(PlayerClass playerClass);
	const std::string& getPlayerHitAnimName(PlayerClass playerClass);

	// PlayerSummaryGui Constants
	const sf::Vector2f c_rootPosition = sf::Vector2f(350, 150);
	const float c_rootHeight = 600;
	const float c_rootWidth = 400;

	const sf::Vector2f c_firstChildRelativePosition = sf::Vector2f(10, 10);
	const float c_firstChildHeight = 580;
	const float c_firstChildWidth = 380;

	const sf::Vector2f c_firstChildAbsolutePosition = sf::Vector2f(
		c_rootPosition.x + c_firstChildRelativePosition.x,
		c_rootPosition.y + c_firstChildRelativePosition.y
	);

	const sf::Vector2f c_titlePosition = sf::Vector2f(c_firstChildWidth / 2 - 110, 5);
	const sf::Vector2f c_namePosition = sf::Vector2f(c_firstChildWidth / 2 - 90, 55);
	const sf::Vector2f c_levelPosition = sf::Vector2f(c_firstChildWidth / 2 - 90, 80);

	const sf::Vector2f c_strengthPosition = sf::Vector2f(15, 125);
	const sf::Vector2f c_wisdomPosition = sf::Vector2f(15, 150);
	const sf::Vector2f c_conditioningPosition = sf::Vector2f(15, 175);
	const sf::Vector2f c_agilityPosition = sf::Vector2f(15, 200);

	const std::string c_titleString = "Character Summary";
	const std::string c_levelLabel = "Level: ";

	const std::string c_strengthLabel = "Strength: ";
	const std::string c_wisdomLabel = "Wisdom: ";
	const std::string c_conditioningLabel = "Conditioning: ";
	const std::string c_agilityLabel = "Agility: ";

	const std::string c_playerSummaryGuiFontFileName = "fonts/dpcomic.ttf";
};