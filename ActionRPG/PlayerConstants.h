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

	const std::string c_strengthLabel = "Strength: ";
	const std::string c_wisdomLabel = "Wisdom: ";
	const std::string c_conditioningLabel = "Conditioning: ";
	const std::string c_agilityLabel = "Agility: ";
	
	std::string c_idleAnimName;
	std::string c_runAnimName;
	std::string c_hitAnimName;

	const std::string& getPlayerIdleAnimName(PlayerClass playerClass);
	const std::string& getPlayerRunAnimName(PlayerClass playerClass);
	const std::string& getPlayerHitAnimName(PlayerClass playerClass);

	const std::string c_playerSummaryGuiFontFileName = "fonts/dpcomic.ttf";
};