#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class PlayerConstants {
public:
	// Player Constants

	const static int c_halfDenominator = 2;

	// Player Class enum
	const enum class PlayerClass { Knight, Wizard, Elf, Dino };

	// Starting level
	const static int c_startingLevel = 1;

	// Starting base health, speed, and mana
	// These are placeholder values
	const static int c_startingHealth = 100;
	const static int c_startingSpeed = 200;
	const static int c_startingMana = 100;

	// Starting base attributes
	const static int c_startingStrength = 4;
	const static int c_startingWisdom = 4;
	const static int c_startingConditioning = 4;
	const static int c_startingAgility = 4;
	
	// Player anim stuff
	std::string c_idleAnimName;
	std::string c_runAnimName;
	std::string c_hitAnimName;

	const std::string& getPlayerIdleAnimName(PlayerClass playerClass);
	const std::string& getPlayerRunAnimName(PlayerClass playerClass);
	const std::string& getPlayerHitAnimName(PlayerClass playerClass);

	const static int c_playerAnimScalingFactor = 2;
	const float c_playerAnimSpeed = 0.1f;

	// Player weapon anim stuff
	// TODO: Not only for knife, but for all weapons
	std::string c_weaponIdleAnimName = "knife_idle_anim";
	std::string c_weaponSwingAnimName = "knife_swing_anim";

	const static int c_weaponAnimScalingFactor = 1;
	const float c_weaponAnimSpeed = 0.023f;

	const float c_weaponPositionOffsetX = 3;
	const float c_weaponPositionOffsetY = -10;

	// Player weapon hitbox anim stuff
	std::string c_weaponSwingHitboxAnimName = "knife_hitbox_anim";
	const static int c_weaponHitboxAnimScalingFactor = 1;
	const float c_weaponHitboxAnimSpeed = 0.02f;

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

	const float c_midPos = c_firstChildWidth / 2;
	const float c_topPadding = 5;
	const float c_leftPadding = 25;
	const float c_textLineSeparationPadding = 25;

	const sf::Vector2f c_titlePosition = sf::Vector2f(c_midPos - 110, c_topPadding);
	const sf::Vector2f c_namePosition = sf::Vector2f(c_midPos - 90, c_topPadding + 2 * c_textLineSeparationPadding);
	const sf::Vector2f c_levelPosition = sf::Vector2f(c_midPos - 90, c_topPadding + 3 * c_textLineSeparationPadding);
	const sf::Vector2f c_attributesTitlePosition = sf::Vector2f(c_midPos - 60, c_topPadding + 5 * c_textLineSeparationPadding);

	const sf::Vector2f c_strengthPosition = sf::Vector2f(c_leftPadding, c_topPadding + 7 * c_textLineSeparationPadding);
	const sf::Vector2f c_wisdomPosition = sf::Vector2f(c_leftPadding, c_topPadding + 8 * c_textLineSeparationPadding);
	const sf::Vector2f c_conditioningPosition = sf::Vector2f(c_leftPadding, c_topPadding + 9 * c_textLineSeparationPadding);
	const sf::Vector2f c_agilityPosition = sf::Vector2f(c_leftPadding, c_topPadding + 10 * c_textLineSeparationPadding);

	const std::string c_titleString = "Character Summary";
	const std::string c_levelLabel = "Level ";

	const std::string c_attributesTitleString = "Attributes";
	const std::string c_strengthLabel = "Strength: ";
	const std::string c_wisdomLabel = "Wisdom: ";
	const std::string c_conditioningLabel = "Conditioning: ";
	const std::string c_agilityLabel = "Agility: ";

	const std::string c_playerSummaryGuiFontFileName = "fonts/dpcomic.ttf";
};