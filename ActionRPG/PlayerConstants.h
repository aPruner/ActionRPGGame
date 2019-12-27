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
	const static int c_startingStrength = 4;
	const static int c_startingWisdom = 4;
	const static int c_startingConditioning = 4;
	const static int c_startingAgility = 4;
	
	// TODO: Figure out how to define static strings so there is no need to instantiate this class
	std::string c_idleAnimName;
	std::string c_runAnimName;
	std::string c_hitAnimName;

	const std::string& getPlayerIdleAnimName(PlayerClass playerClass);
	const std::string& getPlayerRunAnimName(PlayerClass playerClass);
	const std::string& getPlayerHitAnimName(PlayerClass playerClass);
};